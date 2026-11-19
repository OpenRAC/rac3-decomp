#include "common.h"

/* declared by functions of L39_00508470.c, which this file was cut from */
extern s32 func_L39_004F6060(void *, s32 **, s32);
extern void func_L39_004F74E8(void *, s32, s32);

/* localdecomp:start func_L39_00508758 */
typedef struct {
    u8 b[8];
} S8_00508758;

typedef struct {
    s32 pad0[3];
    void *unkC;
    u8 *unk10;
    S8_00508758 unk14;
    s32 unk1C;
    s32 unk20;
} Obj_00508758;

typedef struct {
    void *vtbl;
    s32 pad4[3];
    Obj_00508758 *obj;
    s32 unk14;
} Buf_00508758;

extern void *func_L39_004F7590(s32);
extern void func_L39_004F5F80(void *);
extern void func_L39_004F7620(void *);
extern u8 D_L39_0046F010[];

s32 func_L39_00508758(void **arg0, s32 count, s32 arg2, s32 arg3, S8_00508758 *arg4) {
    s32 size;
    Obj_00508758 *obj;
    Buf_00508758 *buf;
    u8 *p;

    obj = func_L39_004F7590(0x24);
    if (obj == 0) {
        return 0x206;
    }
    func_L39_004F74E8(obj, 0, 0x24);
    func_L39_004F5F80(obj);
    size = count * 4;
    p = func_L39_004F7590(size + 0x20);
    if (p == 0) {
        func_L39_004F7620(obj);
        return 0x206;
    }
    func_L39_004F74E8(p, 0, size + 0x20);
    buf = (Buf_00508758 *)p;
    p += 0x18;
    buf->vtbl = D_L39_0046F010;
    buf->obj = obj;
    buf->unk14 = 0;
    obj->unk20 = arg3;
    obj->unk1C = arg2;
    p = p - ((u32)p & 7) + 8;
    obj->unk10 = p;
    if (arg4 != 0) {
        obj->unk14 = *arg4;
    }
    if (func_L39_004F6060(obj, (s32 **)arg0, size) != 0) {
        func_L39_004F7620(buf->obj);
        func_L39_004F7620(buf);
        return 0x206;
    }
    func_L39_004F74E8(*arg0, 0xFF, size);
    obj->unkC = *arg0;
    ((void **)((u8 *)*arg0 + size))[-2] = buf;
    ((void **)((u8 *)*arg0 + size))[-1] = 0;
    return 0;
}
/* localdecomp:end func_L39_00508758 */
