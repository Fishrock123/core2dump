#ifndef SRC_V8_CONSTANTS_H_
#define SRC_V8_CONSTANTS_H_

#include "error.h"
#include "obj.h"

static const int kCDV8RegExpPattern = 1;
static const int kCDV8MapFieldOffset = 4;
static const int kCDV8MapFieldCount = 2;

#define CD_V8_CONSTANTS_ENUM(X)                                               \
    X(AsciiStringTag)                                                         \
    X(ConsStringTag)                                                          \
    X(ExternalStringTag)                                                      \
    X(FailureTag)                                                             \
    X(FailureTagMask)                                                         \
    X(FirstNonstringType)                                                     \
    X(HeapObjectTag)                                                          \
    X(HeapObjectTagMask)                                                      \
    X(IsNotStringMask)                                                        \
    X(NotStringTag)                                                           \
    X(PointerSizeLog2)                                                        \
    X(SeqStringTag)                                                           \
    X(ConsStringTag)                                                          \
    X(SlicedStringTag)                                                        \
    X(SmiShiftSize)                                                           \
    X(SmiTag)                                                                 \
    X(SmiTagMask)                                                             \
    X(SmiValueShift)                                                          \
    X(StringEncodingMask)                                                     \
    X(StringRepresentationMask)                                               \
    X(StringTag)                                                              \
    X(TwoByteStringTag)                                                       \
    X(class_ConsString__first__String)                                        \
    X(class_ConsString__second__String)                                       \
    X(class_ExternalString__resource__Object)                                 \
    X(class_FixedArrayBase__length__SMI)                                      \
    X(class_FixedArray__data__uintptr_t)                                      \
    X(class_FreeSpace__size__SMI)                                             \
    X(class_GlobalObject__builtins__JSBuiltinsObject)                         \
    X(class_GlobalObject__global_context__Context)                            \
    X(class_GlobalObject__global_receiver__JSObject)                          \
    X(class_GlobalObject__native_context__Context)                            \
    X(class_HeapNumber__value__double)                                        \
    X(class_HeapObject__map__Map)                                             \
    X(class_JSObject__elements__Object)                                       \
    X(class_JSArray__length__Object)                                          \
    X(class_JSFunction__literals_or_bindings__FixedArray)                     \
    X(class_JSFunction__next_function_link__Object)                           \
    X(class_JSFunction__prototype_or_initial_map__Object)                     \
    X(class_JSFunction__shared__SharedFunctionInfo)                           \
    X(class_JSMap__table__Object)                                             \
    X(class_JSObject__properties__FixedArray)                                 \
    X(class_Map__bit_field3__SMI)                                             \
    X(class_Map__code_cache__Object)                                          \
    X(class_Map__constructor__Object)                                         \
    X(class_Map__dependent_code__DependentCode)                               \
    X(class_Map__inobject_properties__int)                                    \
    X(class_Map__instance_attributes__int)                                    \
    X(class_Map__instance_descriptors__DescriptorArray)                       \
    X(class_Map__instance_size__int)                                          \
    X(class_NameDictionaryShape__prefix_size__int)                            \
    X(class_NameDictionaryShape__entry_size__int)                             \
    X(class_SeqOneByteString__chars__char)                                    \
    X(class_SeqTwoByteString__chars__char)                                    \
    X(class_SharedFunctionInfo__inferred_name__String)                        \
    X(class_SharedFunctionInfo__name__Object)                                 \
    X(class_SharedFunctionInfo__script__Object)                               \
    X(class_SlicedString__offset__SMI)                                        \
    X(class_String__length__SMI)                                              \
    X(class_JSRegExp__data__Object)                                           \
    X(frametype_ArgumentsAdaptorFrame)                                        \
    X(frametype_ConstructFrame)                                               \
    X(frametype_EntryConstructFrame)                                          \
    X(frametype_EntryFrame)                                                   \
    X(frametype_ExitFrame)                                                    \
    X(frametype_InternalFrame)                                                \
    X(frametype_JavaScriptFrame)                                              \
    X(frametype_OptimizedFrame)                                               \
    X(bit_field3_dictionary_map_shift)                                        \
    X(off_fp_args)                                                            \
    X(off_fp_context)                                                         \
    X(off_fp_function)                                                        \
    X(off_fp_marker)                                                          \
    X(parent_ConsString__String)                                              \
    X(prop_desc_details)                                                      \
    X(prop_desc_key)                                                          \
    X(prop_desc_size)                                                         \
    X(prop_desc_value)                                                        \
    X(prop_idx_first)                                                         \
    X(prop_type_field)                                                        \
    X(prop_type_first_phantom)                                                \
    X(prop_type_mask)                                                         \
    X(type_AccessorPair__ACCESSOR_PAIR_TYPE)                                  \
    X(type_AccessCheckInfo__ACCESS_CHECK_INFO_TYPE)                           \
    X(type_AliasedArgumentsEntry__ALIASED_ARGUMENTS_ENTRY_TYPE)               \
    X(type_AllocationMemento__ALLOCATION_MEMENTO_TYPE)                        \
    X(type_AllocationSite__ALLOCATION_SITE_TYPE)                              \
    X(type_SeqOneByteString__ASCII_STRING_TYPE)                               \
    X(type_BreakPointInfo__BREAK_POINT_INFO_TYPE)                             \
    X(type_ByteArray__BYTE_ARRAY_TYPE)                                        \
    X(type_CallHandlerInfo__CALL_HANDLER_INFO_TYPE)                           \
    X(type_Cell__CELL_TYPE)                                                   \
    X(type_CodeCache__CODE_CACHE_TYPE)                                        \
    X(type_Code__CODE_TYPE)                                                   \
    X(type_ConstantPoolArray__CONSTANT_POOL_ARRAY_TYPE)                       \
    X(type_ConsString__CONS_ASCII_STRING_TYPE)                                \
    X(type_ConsString__CONS_STRING_TYPE)                                      \
    X(type_DebugInfo__DEBUG_INFO_TYPE)                                        \
    X(type_DeclaredAccessorDescriptor__DECLARED_ACCESSOR_DESCRIPTOR_TYPE)     \
    X(type_DeclaredAccessorInfo__DECLARED_ACCESSOR_INFO_TYPE)                 \
    X(type_ExecutableAccessorInfo__EXECUTABLE_ACCESSOR_INFO_TYPE)             \
    X(type_ExternalAsciiString__EXTERNAL_ASCII_STRING_TYPE)                   \
    X(type_ExternalFloat32Array__EXTERNAL_FLOAT32_ARRAY_TYPE)                 \
    X(type_ExternalFloat64Array__EXTERNAL_FLOAT64_ARRAY_TYPE)                 \
    X(type_ExternalInt16Array__EXTERNAL_INT16_ARRAY_TYPE)                     \
    X(type_ExternalInt32Array__EXTERNAL_INT32_ARRAY_TYPE)                     \
    X(type_ExternalInt8Array__EXTERNAL_INT8_ARRAY_TYPE)                       \
    X(type_ExternalTwoByteString__EXTERNAL_STRING_TYPE)                       \
    X(type_ExternalUint16Array__EXTERNAL_UINT16_ARRAY_TYPE)                   \
    X(type_ExternalUint32Array__EXTERNAL_UINT32_ARRAY_TYPE)                   \
    X(type_ExternalUint8Array__EXTERNAL_UINT8_ARRAY_TYPE)                     \
    X(type_ExternalUint8ClampedArray__EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE)      \
    X(type_FixedArray__FIXED_ARRAY_TYPE)                                      \
    X(type_FixedDoubleArray__FIXED_DOUBLE_ARRAY_TYPE)                         \
    X(type_Foreign__FOREIGN_TYPE)                                             \
    X(type_FreeSpace__FREE_SPACE_TYPE)                                        \
    X(type_FunctionTemplateInfo__FUNCTION_TEMPLATE_INFO_TYPE)                 \
    X(type_HeapNumber__HEAP_NUMBER_TYPE)                                      \
    X(type_InterceptorInfo__INTERCEPTOR_INFO_TYPE)                            \
    X(type_JSArrayBuffer__JS_ARRAY_BUFFER_TYPE)                               \
    X(type_JSArray__JS_ARRAY_TYPE)                                            \
    X(type_JSBuiltinsObject__JS_BUILTINS_OBJECT_TYPE)                         \
    X(type_JSDataView__JS_DATA_VIEW_TYPE)                                     \
    X(type_JSDate__JS_DATE_TYPE)                                              \
    X(type_JSFunctionProxy__JS_FUNCTION_PROXY_TYPE)                           \
    X(type_JSFunction__JS_FUNCTION_TYPE)                                      \
    X(type_JSGeneratorObject__JS_GENERATOR_OBJECT_TYPE)                       \
    X(type_JSGlobalObject__JS_GLOBAL_OBJECT_TYPE)                             \
    X(type_JSMap__JS_MAP_TYPE)                                                \
    X(type_JSMessageObject__JS_MESSAGE_OBJECT_TYPE)                           \
    X(type_JSModule__JS_MODULE_TYPE)                                          \
    X(type_JSObject__JS_OBJECT_TYPE)                                          \
    X(type_JSProxy__JS_PROXY_TYPE)                                            \
    X(type_JSRegExp__JS_REGEXP_TYPE)                                          \
    X(type_JSSet__JS_SET_TYPE)                                                \
    X(type_JSTypedArray__JS_TYPED_ARRAY_TYPE)                                 \
    X(type_JSValue__JS_VALUE_TYPE)                                            \
    X(type_JSWeakMap__JS_WEAK_MAP_TYPE)                                       \
    X(type_JSWeakSet__JS_WEAK_SET_TYPE)                                       \
    X(type_Map__MAP_TYPE)                                                     \
    X(type_ObjectTemplateInfo__OBJECT_TEMPLATE_INFO_TYPE)                     \
    X(type_Oddball__ODDBALL_TYPE)                                             \
    X(type_PolymorphicCodeCache__POLYMORPHIC_CODE_CACHE_TYPE)                 \
    X(type_PropertyCell__PROPERTY_CELL_TYPE)                                  \
    X(type_Script__SCRIPT_TYPE)                                               \
    X(type_SharedFunctionInfo__SHARED_FUNCTION_INFO_TYPE)                     \
    X(type_SignatureInfo__SIGNATURE_INFO_TYPE)                                \
    X(type_SlicedString__SLICED_ASCII_STRING_TYPE)                            \
    X(type_SlicedString__SLICED_STRING_TYPE)                                  \
    X(type_SeqTwoByteString__STRING_TYPE)                                     \
    X(type_SeqTwoByteString__SYMBOL_TYPE)                                     \
    X(type_TypeFeedbackInfo__TYPE_FEEDBACK_INFO_TYPE)                         \
    X(type_TypeSwitchInfo__TYPE_SWITCH_INFO_TYPE)                             \

#define CD_V8_CONSTANT_VALUE(V) int cd_v8_##V;
CD_V8_CONSTANTS_ENUM(CD_V8_CONSTANT_VALUE);
#undef CD_V8_CONSTANT_VALUE

#define CD_V8_TYPE(M, S) cd_v8_type_##M##__##S##_TYPE

cd_error_t cd_v8_init(cd_obj_t* binary, cd_obj_t* core);

#endif  /* SRC_V8_CONSTANTS_H_ */
