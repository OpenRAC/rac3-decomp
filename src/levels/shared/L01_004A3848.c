#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* localdecomp:start func_L01_004A3848 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xAA - 0x36];
    s16 fAA;
    u8 padAC[0xB2 - 0xAC];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90_004A3848;
typedef int u128_004A3848 __attribute__((mode(TI)));
typedef struct {
    s32 valid;
    u8 pad04[0xC];
    u128_004A3848 q10;
    u128_004A3848 q20;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 b3C, b3D, b3E, b3F, b40, b41;
    u8 pad42[2];
    f32 f44, f48, f4C, f50;
    s32 w54;
    s32 w58;
    s32 w5C;
    u8 data60[0xC04];
    s32 wC64;
    s32 wC68;
    u8 padC6C[4];
} Ckpt_004A3848;
typedef struct {
    u8 pad0[0x20];
    u8 v20[0x10];
    u8 pad30[0x68];
    f32 f98;
    u8 pad9C[0x1540 - 0x9C];
    u8 b1540[0x16CC - 0x1540];
    f32 f16CC;
    u8 pad16D0[0x25C0 - 0x16D0];
    u8 *p25C0;
    u8 pad25C4[0x25F7 - 0x25C4];
    u8 b25F7;
} Hero_004A3848;
typedef struct {
    u8 pad0[0x40];
    u8 b40, b41, b42, b43;
    u8 pad44[0xB4 - 0x44];
    s32 wB4;
} Tab_004A3848;
typedef struct {
    u8 pad0[0x48];
    s16 h48;
} Flg_004A3848;

extern Hero_004A3848 D_001A4BE0;
extern Ckpt_004A3848 D_L01_00237800;
extern Ckpt_004A3848 D_L01_00236B90;
extern Tab_004A3848 D_001A30B0;
extern Flg_004A3848 D_001CCFD0;
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001DF9E4;
__asm__(".extern D_L01_001DF9E4, 16");
extern u8 D_L01_001DF9E5;
__asm__(".extern D_L01_001DF9E5, 16");
extern u8 D_L01_001DF9E6;
__asm__(".extern D_L01_001DF9E6, 16");
extern f32 D_L01_001DF9E8;
__asm__(".extern D_L01_001DF9E8, 16");
extern f32 D_L01_001DF9EC;
__asm__(".extern D_L01_001DF9EC, 16");
extern f32 D_L01_001DF9F0;
__asm__(".extern D_L01_001DF9F0, 16");
extern f32 D_L01_001DF9F4;
extern Type_004A3A90_004A3848 *D_L01_001E001C;
extern Type_004A3A90_004A3848 *D_L01_001E0020;
__asm__(".extern D_L01_001E001C, 16");
__asm__(".extern D_L01_001E0020, 16");
extern void func_0038CB78(void *, s32, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_L01_0042B068(s32, s32);
extern void func_L01_004ED3F8(s32, s32, void *);
extern void func_003C7C38(void *);
extern void func_0038D308(void *, void *);
extern void func_L01_003F5AC0(s32, s32);
extern void func_L01_004A3B88(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412FE0(void *, void *, f32, f32);

void func_L01_004A3848(void) {
    vu0_v4 v;
    s32 i;
    s32 id;
    D_001A4BE0.b25F7 = 15;
    if (D_L01_00237800.valid == 0) {
        func_0038CB78(&D_L01_00236B90, 0, 0xC70);
        return;
    }
    func_0038CC88(&D_L01_00236B90, &D_L01_00237800, 0xC70);
    *(u128_004A3848 *)((u8 *)&D_001A4BE0 + 0x80) = D_L01_00237800.q10;
    *(u128_004A3848 *)((u8 *)&D_001A4BE0 + 0x90) = D_L01_00237800.q20;
    *(s32 *)(D_001A4BE0.p25C0 + 0x38) = D_L01_00237800.w30;
    *(s32 *)(D_001A4BE0.p25C0 + 0x3C) = D_L01_00237800.w34;
    D_001A30B0.wB4 = D_L01_00237800.w38;
    D_001A30B0.b40 = D_L01_00237800.b3C;
    D_001A30B0.b41 = D_L01_00237800.b3D;
    D_001A30B0.b42 = D_L01_00237800.b3E;
    D_001A30B0.b43 |= 7;
    D_001CCFD0.h48 = D_L01_00237800.wC64;
    if (D_L01_001F3F40[0] != D_L01_00237800.wC68) {
        func_L01_0042B068(D_L01_00237800.wC68, D_L01_00237800.wC64);
    }
    D_L01_001DF9E4 = D_L01_00237800.b3F;
    D_L01_001DF9E5 = D_L01_00237800.b40;
    D_L01_001DF9E6 = D_L01_00237800.b41;
    D_L01_001DF9E8 = D_L01_00237800.f44;
    D_L01_001DF9EC = D_L01_00237800.f48;
    D_L01_001DF9F0 = D_L01_00237800.f4C;
    D_L01_001DF9F4 = D_L01_00237800.f50;
    id = D_L01_00237800.w54;
    if (id != 0 && id != 3) {
        s32 want = 0;
        switch (id) {
        case 1:
            want = 0x57;
            break;
        case 2:
            want = 0x1A3;
            break;
        default:
            break;
        }
        for (i = 0; &D_L01_001E001C[i] < D_L01_001E0020; i++) {
            if (D_L01_001E001C[i].fAA == want) {
                func_L01_004ED3F8(D_L01_00237800.w54, D_L01_00237800.w5C, &D_L01_001E001C[i]);
                break;
            }
        }
    }
    func_003C7C38(D_001A4BE0.p25C0);
    func_0038D308(D_001A4BE0.p25C0 + 0xC0, (u8 *)&D_001A4BE0 + 0x90);
    func_L01_003F5AC0(0, 1);
    func_L01_004A3B88();
    func_0038CF68(&v, D_001A4BE0.v20, D_001A4BE0.f16CC);
    vec_add_ab(&v, &v, (u8 *)&D_001A4BE0 + 0x80);
    func_L01_00412FE0(D_001A4BE0.b1540, &v, D_001A4BE0.f98, 0.0f);
}
/* localdecomp:end func_L01_004A3848 */
