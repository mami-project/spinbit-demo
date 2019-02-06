/*
 * VLIB API definitions Tue May  1 20:50:25 2018
 * Input file: spinbit/spinbit.api.h
 * Automatically generated: please edit the input file NOT this file!
 */

#if defined(vl_msg_id)||defined(vl_union_id)||defined(vl_printfun) \
 ||defined(vl_endianfun)|| defined(vl_api_version)||defined(vl_typedefs) \
 ||defined(vl_msg_name)||defined(vl_msg_name_crc_list)
/* ok, something was selected */
#else
#warning no content included from spinbit/spinbit.api.h
#endif

#define VL_API_PACKED(x) x __attribute__ ((packed))


/****** Message ID / handler enum ******/

#ifdef vl_msg_id
vl_msg_id(VL_API_SPINBIT_ENABLE_DISABLE, vl_api_spinbit_enable_disable_t_handler)
vl_msg_id(VL_API_SPINBIT_ENABLE_DISABLE_REPLY, vl_api_spinbit_enable_disable_reply_t_handler)
#endif

/****** Message names ******/

#ifdef vl_msg_name
vl_msg_name(vl_api_spinbit_enable_disable_t, 1)
vl_msg_name(vl_api_spinbit_enable_disable_reply_t, 1)
#endif


/****** Message name, crc list ******/

#ifdef vl_msg_name_crc_list
#define foreach_vl_msg_name_crc_spinbit \
_(VL_API_SPINBIT_ENABLE_DISABLE, spinbit_enable_disable, 942ce439) \
_(VL_API_SPINBIT_ENABLE_DISABLE_REPLY, spinbit_enable_disable_reply, 23dafddc) 
#endif


/****** Typedefs *****/

#ifdef vl_typedefs

typedef VL_API_PACKED(struct _vl_api_spinbit_enable_disable {
    u16 _vl_msg_id;
    u32 client_index;
    u32 context;
    u8 enable_disable;
    u32 sw_if_index;
}) vl_api_spinbit_enable_disable_t;

typedef VL_API_PACKED(struct _vl_api_spinbit_enable_disable_reply {
    u16 _vl_msg_id;
    u32 context;
    i32 retval;
}) vl_api_spinbit_enable_disable_reply_t;

#endif /* vl_typedefs */

/****** Discriminated Union Definitions *****/

#ifdef vl_union_id


#endif /* vl_union_id */

/****** Print functions *****/

#ifdef vl_printfun

#ifdef LP64
#define _uword_fmt "%lld"
#define _uword_cast (long long)
#else
#define _uword_fmt "%ld"
#define _uword_cast long
#endif

static inline void *vl_api_spinbit_enable_disable_t_print (vl_api_spinbit_enable_disable_t *a,void *handle)
{
    vl_print(handle, "vl_api_spinbit_enable_disable_t:\n");
    vl_print(handle, "_vl_msg_id: %u\n", (unsigned) a->_vl_msg_id);
    vl_print(handle, "client_index: %u\n", (unsigned) a->client_index);
    vl_print(handle, "context: %u\n", (unsigned) a->context);
    vl_print(handle, "enable_disable: %u\n", (unsigned) a->enable_disable);
    vl_print(handle, "sw_if_index: %u\n", (unsigned) a->sw_if_index);
    return handle;
}

static inline void *vl_api_spinbit_enable_disable_reply_t_print (vl_api_spinbit_enable_disable_reply_t *a,void *handle)
{
    vl_print(handle, "vl_api_spinbit_enable_disable_reply_t:\n");
    vl_print(handle, "_vl_msg_id: %u\n", (unsigned) a->_vl_msg_id);
    vl_print(handle, "context: %u\n", (unsigned) a->context);
    vl_print(handle, "retval: %ld\n", (long) a->retval);
    return handle;
}

#endif /* vl_printfun */


/****** Endian swap functions *****/

#ifdef vl_endianfun

#undef clib_net_to_host_uword
#ifdef LP64
#define clib_net_to_host_uword clib_net_to_host_u64
#else
#define clib_net_to_host_uword clib_net_to_host_u32
#endif

static inline void vl_api_spinbit_enable_disable_t_endian (vl_api_spinbit_enable_disable_t *a)
{
    a->_vl_msg_id = clib_net_to_host_u16(a->_vl_msg_id);
    a->client_index = clib_net_to_host_u32(a->client_index);
    a->context = clib_net_to_host_u32(a->context);
    /* a->enable_disable = a->enable_disable (no-op) */
    a->sw_if_index = clib_net_to_host_u32(a->sw_if_index);
}

static inline void vl_api_spinbit_enable_disable_reply_t_endian (vl_api_spinbit_enable_disable_reply_t *a)
{
    a->_vl_msg_id = clib_net_to_host_u16(a->_vl_msg_id);
    a->context = clib_net_to_host_u32(a->context);
    a->retval = clib_net_to_host_u32(a->retval);
}

#endif /* vl_endianfun */


#ifdef vl_api_version
vl_api_version(spinbit.api, 0x4b8265e5)

#endif

