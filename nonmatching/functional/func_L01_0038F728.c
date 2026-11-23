/* functional: high. 342 diff = register allocation/scheduling only (whole function shifted). Re-read all branches, struct offsets (move struct 0x30..0x88), constants (-5.0, 0.0048, 0.25, -3.0, 0.2, 1021.0, 1.5..5.5) and callee arg order against asm */
#include "common.h"
#include "vu0.h"
typedef int u128_390A40 __attribute__((mode(TI)));
typedef struct {
    u128_390A40 rotation;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} BurstVars_390A40;
typedef struct {
    u8 pad_0[0x10];
    u128_390A40 position;
    s8 state;
    u8 pad_21[0x30 - 0x21];
    u8 unk_30;
    u8 pad_31[0x68 - 0x31];
    BurstVars_390A40 *vars;
} Moby_390A40;


typedef struct {
    vu0_q start, end, velocity;
    u8 *hit;
    s32 *options;
    s32 mode;
    f32 radius, factor0, factor1;
    s32 flags, unknown;
    u8 pad50[8];
    s32 field58;
    u8 pad5C[4];
} Move_0038F728;
extern s32 D_L01_001D673C __attribute__((section(".data")));
extern u8 *D_001A71A0[];
extern vu0_q D_L01_001EAA20[];
extern u8 D_L01_001D66B0[];
__asm__(".extern D_001DDFE0_sda, 4");
__asm__(".extern D_001DDFE4_sda, 4");
extern f32 D_001DDFE0_sda __attribute__((section(".sdata")));
extern f32 D_001DDFE4_sda __attribute__((section(".sdata")));
void func_L01_0038F728(u8 *obj) {
    extern void func_L01_004471A8(void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_0038FCB8(void *);
    extern s32 func_00382468(s32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_003900F8(void *);
    extern void func_003C5180(void *, void *, s32);
    extern void func_L01_004CAC40(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_004C7E70(Move_0038F728 *, s32);
    extern u8 *func_00382348(void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003A52A0(s32, s32, void *);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    extern Moby_390A40 *func_L01_00390A40(u128_390A40 *, u128_390A40 *);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    vu0_v4 old;
    s32 options[2];
    vu0_v4 direction;
    Move_0038F728 move;
    vu0_v4 point, normal, offset;
    u8 *vars = *(u8 **)(obj + 0x68);
    func_L01_004471A8(obj, 1.0f);
    if (func_L01_004CB2D8()) func_L01_004CAB30(obj + 0x10, obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
    case 1:
        func_L01_0038FCB8(obj);
        if (!D_L01_001D673C && !func_L01_004CB2D8() && func_00382468(2)) {
            func_L01_004C7D98(obj + 0x10, &direction);
            func_0038CF68(&direction, &direction, -5.0f);
            __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "+m"(direction) : "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
            if (func_003D3CB0(obj + 0x10, &direction, 0, D_001A71A0[0], 0)) func_L01_003900F8(D_L01_001EAA20);
        }
        old = *(vu0_v4 *)(obj + 0x10);
        func_003C5180(&old, &direction, 1);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(*(vu0_v4 *)(obj + 0x10)) : "m"(*(vu0_v4 *)vars) : "vf1", "vf2");
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
        func_L01_004CAC40(vars, vars);
        func_L01_004C8688(*(s32 *)(vars + 0x34), vars, 0);
        func_L01_004C7D40(obj + 0x10, vars, 0.0048f);
        move.start = *(vu0_q *)&old;
        move.end = *(vu0_q *)(obj + 0x10);
        options[0] = 0;
        options[1] = 0xCE3;
        move.velocity = *(vu0_q *)vars;
        move.hit = obj;
        move.options = options;
        move.mode = 2;
        move.radius = 0.25f;
        move.factor0 = D_001DDFE0_sda;
        move.factor1 = D_001DDFE4_sda;
        move.flags = 0;
        move.unknown = 0;
        move.field58 = 0;
        if (func_L01_004C7E70(&move, -1) == 2) obj[0x20] = 2;
        *(vu0_q *)(obj + 0x10) = move.end;
        *(vu0_q *)vars = move.velocity;
        *(vu0_q *)(vars + 0x20) = move.start;
        if (move.hit && ((*(u8 **)(move.hit + 0x24))[0x46] == 5 ||
            (*(u8 **)(move.hit + 0x24))[0x46] == 9 || (*(u16 *)(move.hit + 0x34) & 0x4000))) {
            u8 *info = func_00382348(move.hit);
            func_L01_004C7D98(move.hit + 0x10, &normal);
            *(vu0_q *)&point = *(vu0_q *)(obj + 0x10);
            if (info) {
                func_0038CE20((f32 *)&offset, (f32 *)&normal, *(f32 *)(info + 0x10));
                __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "+m"(point) : "m"(offset) : "vf1", "vf2");
            }
            func_0038CE20((f32 *)&normal, (f32 *)&normal, -3.0f);
            obj[0x20] = 2;
            __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(normal) : "m"(point) : "vf1", "vf2");
            *(vu0_q *)(obj + 0x10) = D_L01_001EAA20[0];
            *(vu0_q *)(vars + 0x20) = D_L01_001EAA20[2];
            func_0038CF68(vars + 0x20, vars + 0x20, 1.0f);
            if (func_003D3CB0(&point, &normal, 6, move.hit, 0)) {
                *(vu0_q *)(obj + 0x10) = D_L01_001EAA20[0];
                *(vu0_q *)(vars + 0x20) = D_L01_001EAA20[2];
                func_0038CF68(vars + 0x20, vars + 0x20, 1.0f);
            }
        }
        break;
    case 2:
        func_003A52A0(0, 0, obj);
        if (!D_L01_001D673C && !func_L01_004CB2D8()) {
            s32 i = 0;
            do {
                f32 angle = func_00382538();
                f32 radius = func_003824E0(0, 0.6f);
                f32 size = func_003824E0(0, 1.5f);
                f32 lifetime = func_003824E0(1.5f, 5.5f);
                s32 alpha = func_00382498(100, 160);
                direction.x = func_0038D098(angle) * radius;
                direction.y = func_0038D0B0(angle) * radius;
                direction.z = 0;
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "+m"(direction) : "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
                func_L01_0046B288(&direction, 0x30305020, 0x182810, alpha, size, lifetime);
                i--;
            } while (i >= 0);
        }
        {
            Moby_390A40 *burst = func_L01_00390A40((u128_390A40 *)(obj + 0x10), (u128_390A40 *)D_L01_001D66B0);
            *(s32 *)((u8 *)burst + 0xB8) = *(s32 *)(vars + 0x30);
        }
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(obj);
        return;
    }
    *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(obj + 0xF0), *(f32 *)(vars + 0x10));
    *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), *(f32 *)(vars + 0x14));
    func_L01_004471A8(obj, 0.2f);
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(obj);
    }
}
