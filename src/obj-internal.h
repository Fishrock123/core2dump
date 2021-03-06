#ifndef SRC_OBJ_OBJ_INTERNAL_H_
#define SRC_OBJ_OBJ_INTERNAL_H_

#include "error.h"
#include "common.h"
#include "obj-common.h"
#include "queue.h"

#include <stdint.h>

/* Forward declarations */
struct cd_obj_s;
struct cd_dwarf_cfa_s;

typedef struct cd_obj_method_s cd_obj_method_t;
typedef struct cd_segment_s cd_segment_t;
typedef struct cd_sym_s cd_sym_t;
typedef struct cd_obj_opts_s cd_obj_opts_t;

typedef cd_error_t (*cd_obj_iterate_sym_cb)(struct cd_obj_s* obj,
                                            cd_sym_t* sym,
                                            void* arg);
typedef cd_error_t (*cd_obj_iterate_seg_cb)(struct cd_obj_s* obj,
                                            cd_segment_t* seg,
                                            void* arg);

/* Method types */
typedef struct cd_obj_s* (*cd_obj_method_new_t)(int fd,
                                                cd_obj_opts_t* opts,
                                                cd_error_t* err);
typedef void (*cd_obj_method_free_t)(struct cd_obj_s* obj);
typedef int (*cd_obj_method_is_core_t)(struct cd_obj_s* obj);
typedef cd_error_t (*cd_obj_method_get_thread_t)(struct cd_obj_s* obj,
                                                 unsigned int index,
                                                 cd_obj_thread_t* thread);
typedef cd_error_t (*cd_obj_method_iterate_syms_t)(struct cd_obj_s* obj,
                                                   cd_obj_iterate_sym_cb cb,
                                                   void* arg);
typedef cd_error_t (*cd_obj_method_iterate_segs_t)(struct cd_obj_s* obj,
                                                   cd_obj_iterate_seg_cb cb,
                                                   void* arg);
typedef cd_error_t (*cd_obj_method_get_dbg_frame_t)(struct cd_obj_s* obj,
                                                    void** res,
                                                    uint64_t* size,
                                                    uint64_t* vmaddr);
typedef cd_error_t (*cd_obj_method_use_binary_t)(struct cd_obj_s* obj,
                                                 struct cd_obj_s* binary);

#define CD_OBJ_INTERNAL_FIELDS                                                \
    QUEUE member;                                                             \
    struct cd_obj_method_s* method;                                           \
    const char* path;                                                         \
    int fd;                                                                   \
    void* addr;                                                               \
    size_t size;                                                              \
    int is_x64;                                                               \
    cd_hashmap_t syms;                                                        \
    cd_splay_t sym_splay;                                                     \
    int has_syms;                                                             \
    cd_segment_t* segments;                                                   \
    int segment_count;                                                        \
    cd_splay_t seg_splay;                                                     \
    QUEUE dso;                                                                \
    int64_t aslr;                                                             \
    struct cd_dwarf_cfa_s* cfa;                                               \

struct cd_obj_method_s {
  cd_obj_method_new_t obj_new;
  cd_obj_method_free_t obj_free;
  cd_obj_method_is_core_t obj_is_core;
  cd_obj_method_get_thread_t obj_get_thread;
  cd_obj_method_iterate_syms_t obj_iterate_syms;
  cd_obj_method_iterate_segs_t obj_iterate_segs;
  cd_obj_method_get_dbg_frame_t obj_get_dbg_frame;
  cd_obj_method_use_binary_t obj_use_binary;
};

struct cd_segment_s {
  uint64_t start;
  uint64_t end;
  uint64_t fileoff;
  uint64_t sects;

  char* ptr;
};

struct cd_sym_s {
  const char* name;
  int nlen;
  uint64_t value;
  uint64_t sect;
};

struct cd_obj_opts_s {
  struct cd_obj_s* parent;
  uint64_t reloc;
};


struct cd_obj_s* cd_obj_new_ex(cd_obj_method_t* method,
                               const char* path,
                               cd_obj_opts_t* opts,
                               cd_error_t* err);
cd_error_t cd_obj_internal_init(struct cd_obj_s* obj);
void cd_obj_internal_free(struct cd_obj_s* obj);

/* Platform-specific */
cd_error_t cd_obj_iterate_syms(struct cd_obj_s* obj,
                               cd_obj_iterate_sym_cb cb,
                               void* arg);
cd_error_t cd_obj_iterate_segs(struct cd_obj_s* obj,
                               cd_obj_iterate_seg_cb cb,
                               void* arg);
cd_error_t cd_obj_get_dbg_frame(struct cd_obj_s* obj,
                                void** res,
                                uint64_t* size,
                                uint64_t* vmaddr);

/* Internal, mostly */
cd_error_t cd_obj_init_segments(struct cd_obj_s* obj);

#endif  /* SRC_OBJ_OBJ_INTERNAL_H_ */
