#include "common.h"

/* declared by functions of L39_006979B0.c, which this file was cut from */
typedef struct {
    char pad[0x288];
    s32 f288;
} S_00697B28_slot;
extern S_00697B28_slot *D_L39_00247914;

/* localdecomp:start func_L39_006990C0 */
typedef struct S_006990C0_obj S_006990C0_obj;
typedef struct {
    char pad[0x1C];
    void (*f1C)(S_006990C0_obj *, s32, s32);
    char pad20[0x4];
    void (*f24)(S_006990C0_obj *, void *);
    char pad28[0x40 - 0x28];
    void (*f40)(S_006990C0_obj *, s32);
    char pad44[0x4];
    void (*f48)(S_006990C0_obj *, s32, s32);
    void (*f4C)(S_006990C0_obj *, s32, s32);
} S_006990C0_vt;
struct S_006990C0_obj {
    s32 f0;
    s32 f4;
    char pad[0x60 - 0x8];
    S_006990C0_vt *f60;
};
typedef struct {
    char pad[0x110];
    S_006990C0_obj *f110;
    S_006990C0_obj *f114[6];
} S_006990C0;

extern u8 D_L39_002480C8[];
s32 func_L39_0067F100(s32);
void func_L39_0068AAB8(void *);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_L39_0068B2F8(s32, s32, s32);

void func_L39_006990C0(S_006990C0 *p)
{
    S_006990C0_obj **list;
    s32 i;

    func_L39_0067F100(0x2C0000);
    ((u8 *)D_L39_00247914)[0x280] = 1;
    func_L39_0068AAB8(p);
    func_L39_00689F00(p, 0, 3, 3, 0.4f, 0.6f, 0.2f, 0.05f, 0.0f, 0.0f);
    p->f110->f60->f24(p->f110, D_L39_002480C8);
    p->f110->f60->f40(p->f110, 1);
    p->f110->f60->f1C(p->f110, 1, 0);
    p->f110->f60->f48(p->f110, 1, 1);
    p->f110->f60->f4C(p->f110, 0x40, 1);
    list = p->f114;
    for (i = 5; i >= 0; i--) {
        (*list)->f60->f48(*list, 3, 3);
        (*list)->f60->f40(*list, 1);
        (*list)->f60->f4C(*list, 0x40, 1);
        list++;
    }
    if (p->f114[1]->f4 == 3) {
        func_L39_0068B2F8((s32)p, 2, 0);
    }
    if (p->f114[3]->f4 == 3) {
        func_L39_0068B2F8((s32)p, 4, 0);
    }
    if (p->f114[5]->f4 == 3) {
        func_L39_0068B2F8((s32)p, 6, 0);
    }
}
/* localdecomp:end func_L39_006990C0 */
