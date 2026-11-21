/* PAL near miss (haiku-w4): 228 words differ with the file's flags (contract-only snippet with the owner's typedefs from L01_0035F480.c copied in); retail is 972 bytes and this C is 1028, so the switch, the case 0 branch layout and the callee-saved set still differ, and the VU0 block interleaves the moves. Not for src/ as is. */
#include "common.h"
#include "vu0.h"
typedef struct {
    u8 pad_0[0x18];
    u8 b18;
    u8 b19;
    s16 source_class;
    u8 pad_1C[0x30 - 0x1C];
} DamageInfo_3631C8;
typedef struct Moby_3631C8 {
    u8 pad_0[0x24];
    u8 *pclass;
    u8 pad_28[0x68 - 0x28];
    u8 *vars;
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record;
    u8 pad_9C[0xAA - 0x9C];
    s16 class_id;
} Moby_3631C8;
typedef struct {
    u8 pad_0[0x18];
    Moby_3631C8 *moby;
} CollHit_3631C8;
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_00361AC0;
extern u8 D_001A4BE0[];
extern CollHit_3631C8 D_L01_001EAA00;
extern u8 D_00142617[];
extern Gun_00361AC0 D_L01_002C5600[];
void func_L01_0035E710(u8 *obj) {
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_L01_00446760(DamageInfo_3631C8 *, u8 *, s32, void *, f32);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_0035EB20(void *);
    extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0035EF20(u8 *);
    extern void func_L01_0035F048(void *, void *, void *);
    S_38C110v previous;
    S_38C110v push;
    DamageInfo_3631C8 info;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *hero;
    u8 *position;
    switch (obj[0x20]) {
    case 0:
        position = obj + 0x10;
        previous = *(S_38C110v *)(obj + 0x10);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(S_38C110v *)(obj + 0x10))
            : "m"(*(S_38C110v *)(obj + 0x10)), "m"(*(S_38C110v *)v) : "vf1", "vf2");
        if (func_L01_004CB2D8()) func_L01_004CAB30(position, position);
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
            *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
            *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) goto destroy;
        ++*(s32 *)(v + 0x14);
        hero = D_001A4BE0;
        *(s32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0x98) = 0;
        if (func_003D3CB0(&previous, position, 0x20, obj, 0)) {
            u8 *hit = (u8 *)D_L01_001EAA00.moby;
            if (hit == 0 || hit != *(u8 **)(v + 0x1C)) {
                obj[0x20] = 1;
                *(s128 *)(obj + 0x10) = *(s128 *)((u8 *)&D_L01_001EAA00 + 0x20);
                push = *(S_38C110v *)v;
                func_0038CE20((s128 *)&push, (s128 *)&push, 3.0f);
                push.w = 5627.9248046875f;
                func_L01_00446760(&info, obj, *(s32 *)(v + 0x28), &push, *(f32 *)(v + 0x24));
                info.source_class = *(u16 *)(obj + 0xAA);
                info.b19 = 1;
                info.b18 = 0;
                if (D_L01_001EAA00.moby != 0) {
                    if ((u8 *)D_L01_001EAA00.moby != *(u8 **)(v + 0x1C))
                        func_003D4D00((u8 *)&D_L01_001EAA00 + 0x20, 0, 1.0f, obj, &info);
                } else {
                    func_003D4D00((u8 *)&D_L01_001EAA00 + 0x20, 0, 0.6f, obj, &info);
                }
            }
        }
        { u8 *m = *(u8 **)(D_001A4BE0 + 0x25C0);
          *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10); }
        if (*(s32 *)(v + 0x14) >= 151 || func_L01_0040E548(position, D_001A4BE0 + 0x80) > 6400.0f) goto destroy;
        break;
    case 1:
        if (((Gun_00361AC0 *)((s32)D_L01_002C5600 + D_00142617[0] * 0xF0))->kind >= 2) {
            func_L01_0035EB20(obj + 0x10);
        } else {
            func_L01_003303B8(obj + 0x10, 0, 5, 2, 2, 2, 2, 0, 0.2f, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                0x7F60A0FF, 0x280000FF, 0xFF6430, 0);
        }
        goto destroy;
    }
    goto draw;
destroy:
    func_003C2880(obj);
    return;
draw:
    push = *(S_38C110v *)(obj + 0x10);
    push.w = 0.5f;
    if (func_0038DC20(&push, 96.0f) > 0) {
        func_L01_00404A10(func_L01_0035EF20, obj);
        *(S_38C110v *)&info = *(S_38C110v *)(obj + 0x10);
        func_L01_0035F048(obj, &info, &previous);
    }
    return;
}
