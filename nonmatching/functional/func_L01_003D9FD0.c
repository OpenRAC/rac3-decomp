/* functional: high. Codex near miss, 107 words differ only by branch offsets (one extra retail slot) and order of the sq and of add.s/swc1 around the func_L01_003DA6E8 call; I fixed func_00382348 to take the target moby (retail passes it in a0). */
#include "common.h"
/* localdecomp:start func_L01_003D9FD0 */
#include "vu0.h"
typedef struct { f32 r,g,b,padC,x,y,z,radius; } Light_003D9FD0;
extern Light_003D9FD0 D_L01_001F1B40[];
s32 func_L01_003D9FD0(u8 *obj) {
    extern void func_L01_004471A8(void *, f32);
    extern void func_0038CAD0(void *);
    extern s32 func_L01_00424B88(void *, f32, f32, u32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern u8 *func_L01_00450010(void *, f32, f32, f32, f32, s32);
    extern u8 *func_00382348(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_003DA6E8(void *);
    extern void func_L01_003DABC8(void *);
    vu0_v4 pos;
    vu0_v4 targetpos;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *objpos;
    f32 phase, bob;
    s32 color;
    if (!state) return 1;
    objpos = obj+0x10;
    func_L01_004471A8(obj, 0.6f);
    func_0038CAD0(state + 0x4C);
    if (*(s32 *)(state + 0x30) == -1)
        *(s32 *)(state + 0x30) = func_L01_00424B88(objpos, 5.5f, 0.0f, 0x4080FF);
    *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
    if (*(s32 *)(state + 0x30) >= 0) {
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->x = pos.x;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->y = pos.y;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->z = pos.z;
        phase = func_003824E0(800.0f,160.0f) * 0.01745329238474369f;
        phase = func_0038DAB8(*(f32 *)(state+0x34), phase * 0.020000001415610313f);
        *(f32 *)(state+0x34) = phase;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->radius = (func_0038D0B0(phase * 0.1f) * 0.5f + 0.5f) + 3.5f;
        color = func_0038DBD8(0x3065FF,0x5585FF,func_0038D0B0(*(f32 *)(state+0x34))*0.5f+0.5f);
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->r = (color & 255) * 0.0078125f;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->g = ((color >> 8) & 255) * 0.0078125f;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->b = ((color >> 16) & 255) * 0.0078125f;
    }
    if (obj[0x20] != 2 && obj[0x20] != 3 && obj[0x20] != 0) {
        u8 *target;
        *(vu0_q *)&targetpos = *(vu0_q *)(obj+0x10);
        target = func_L01_00450010(&targetpos,1.0471975803375244f,30.0f,-1.0f,-1.0f,0);
        *(u8 **)(state+0x28) = target;
        if (!target || (*(u16 *)(target+0x34)&2) || target[0x20] == 0xFE || target[0x20] == 0xFD ||
            !*(u8 **)(target+0x24) || (*(u8 **)(target+0x24))[0x46] != 5) goto clear_target;
        {
            u8 *data;
            *(vu0_q *)&targetpos = *(vu0_q *)(target+0x10);
            data = func_00382348(target);
            if (data) {
                func_0038CE20(&targetpos, *(u8 **)(state+0x28)+0xE0, *(f32 *)(data+0x10));
                vec_add_ab(&targetpos,&targetpos,*(u8 **)(state+0x28)+0x10);
            }
            if (func_003D3CB0(objpos,&targetpos,2,(s32)obj,0)) {
                *(u8 **)(state+0x28) = 0;
                func_L01_004450F0(obj,3,-1);
                if (obj[0x43] != 3) func_003C3A10(obj,3,0,0);
            } else {
                func_L01_004450F0(obj,2,-1);
                func_003C3A10(obj,5,0,8);
            }
        }
        goto search_done;
clear_target:
        *(u8 **)(state+0x28) = 0;
    }
search_done:
    if (obj[0x20] == 2) {
        *(f32 *)(state+0xC) = func_0038DAB8(*(f32 *)(state+0xC),*(f32 *)(state+8));
        bob = func_0038D0B0(*(f32 *)(state+0xC));
        bob *= func_003824E0(0.01f,0.03f);
    } else {
        *(f32 *)(state+0xC) = func_0038DAB8(*(f32 *)(state+0xC),*(f32 *)(state+8));
        bob = func_0038D0B0(*(f32 *)(state+0xC));
        bob *= func_003824E0(0.0025f,0.0075f);
    }
    *(f32 *)(obj+0x18) += bob;
    func_L01_003DA6E8(obj);
    if (*(s32 *)(state+0x3C) >= 11) func_L01_003DABC8(obj);
    return 0;
}
/* localdecomp:end func_L01_003D9FD0 */
