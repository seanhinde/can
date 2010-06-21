// Generated by eapi (DO NOT EDIT)
#include "eapi_drv.h"
#include "can_sock_drv.h"

void r_struct_i_can_frame(eapi_ctx_t* ctx, struct i_can_frame *ptr)
{
  cbuf_free_binary(&(ptr->data));
}

int d_struct_i_can_frame(eapi_ctx_t* ctx, cbuf_t* c_in, struct i_can_frame *ptr)
{
  uint32_t d_size;
  cbuf_get_uint32(c_in,&d_size);
  cbuf_get_uint32(c_in,&ptr->id);
  cbuf_get_uint8(c_in,&ptr->len);
  cbuf_get_nbinary(c_in,&ptr->data);
  cbuf_get_int(c_in,&ptr->intf);
  cbuf_get_int(c_in,&ptr->ts);
  return 0;
}

int eapi_dispatch(eapi_ctx_t* ctx, unsigned int cmd, cbuf_t* c_in, cbuf_t* c_out)
{
  switch(cmd) {
  case CAN_SOCK_DRV_CMD_IFNAME: {
    int index;
    cbuf_get_int(c_in,&index);
    can_sock_drv_impl_ifname(ctx,c_out,index);
    break;
  }
  case CAN_SOCK_DRV_CMD_IFINDEX: {
    eapi_string_t name;
    cbuf_get_nstring(c_in,&name);
    can_sock_drv_impl_ifindex(ctx,c_out,&name);
    cbuf_free_string(&(name));
    break;
  }
  case CAN_SOCK_DRV_CMD_SET_ERROR_FILTER: {
    uint32_t mask;
    cbuf_get_uint32(c_in,&mask);
    can_sock_drv_impl_set_error_filter(ctx,c_out,mask);
    break;
  }
  case CAN_SOCK_DRV_CMD_SET_LOOPBACK: {
    uint8_t enable;
    cbuf_get_boolean(c_in,&enable);
    can_sock_drv_impl_set_loopback(ctx,c_out,enable);
    break;
  }
  case CAN_SOCK_DRV_CMD_RECV_OWN_MESSAGES: {
    uint8_t enable;
    cbuf_get_boolean(c_in,&enable);
    can_sock_drv_impl_recv_own_messages(ctx,c_out,enable);
    break;
  }
  case CAN_SOCK_DRV_CMD_BIND: {
    int index;
    cbuf_get_int(c_in,&index);
    can_sock_drv_impl_bind(ctx,c_out,index);
    break;
  }
  case CAN_SOCK_DRV_CMD_SEND: {
    int index;
    struct i_can_frame frame;
    cbuf_get_int(c_in,&index);
    d_struct_i_can_frame(ctx,c_in,&frame);
    can_sock_drv_impl_send(ctx,c_out,index,&frame);
    r_struct_i_can_frame(ctx,&(frame));
    break;
  }
  default:
    return -1;
  }
  return 0;
}
