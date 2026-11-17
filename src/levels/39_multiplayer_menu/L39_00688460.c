#include "common.h"

/* localdecomp:start func_L39_00688460 */
typedef struct {
    u8 pad0[0x64];
    s32 unk64[0x29];
} S_00688460;
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E51F8(s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 D_L39_0024736C;
__asm__(".extern D_L39_0024736C, 16");
extern s32 D_001DBC5C_sda;
void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5) {
    S_00688460 *p = (S_00688460 *)a0;
    s32 i;

    p->unk64[0] = *(s32 *)p5 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p5, 0x3F, 0x80000000, f1, f2, f3 + 0.006f, f4 + 0.006f, f5);
    func_003E8630(D_L39_0024736C, *(s32 *)p5);
    p->unk64[1] = *(s32 *)p3 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p3, 0x3F, 0x331465B7, f1, f2, f3 + 0.001f, f4 + 0.001f, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p3);
    p->unk64[2] = *(s32 *)p4 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p4, 0x40, 0x802299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p4);
    p->unk64[3] = *(s32 *)p1 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p1, 0x3D, 0x332299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p1);
    p->unk64[4] = *(s32 *)p2 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p2, 0x3E, 0x332299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p2);
    p->unk64[5] = func_L39_0067F1B0();
    func_003E51F8(p->unk64[5]);
    func_L01_00516AA0(p->unk64[5], 1, 0);
    func_L01_00516C78(p->unk64[5], 3, 3);
    func_003E8630(D_L39_0024736C, p->unk64[5]);
    p->unk64[6] = func_L39_0067F1B0();
    func_003E8EF0(p->unk64[6], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f);
    func_L01_00516AA0(p->unk64[6], 1, 0);
    func_003E8630(D_L39_0024736C, p->unk64[6]);
    p->unk64[7] = func_L39_0067F1B0();
    func_003E8EF0(p->unk64[7], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, -1.0f, 0.5f);
    func_L01_00516AA0(p->unk64[7], 1, 0);
    func_003E8630(D_L39_0024736C, p->unk64[7]);
    for (i = 0; i < 30; i++) {
        p->unk64[8 + i] = func_L39_0067F1B0();
        func_003E51F8(p->unk64[8 + i]);
        func_L01_00516AA0(p->unk64[8 + i], 1, 0);
        func_L01_00516C78(p->unk64[8 + i], 3, 3);
        func_003E8630(D_L39_0024736C, p->unk64[8 + i]);
    }
    for (i = 0; i < 1; i++) {
        p->unk64[0x26 + i] = func_L39_0067F1B0();
        func_003E9270(p->unk64[0x26 + i], 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.05f, 0.05f);
        func_L01_00516AA0(p->unk64[0x26 + i], 1, 0);
        func_003E8630(D_L39_0024736C, p->unk64[0x26 + i]);
    }
    for (i = 0; i < 2; i++) {
        p->unk64[0x27 + i] = func_L39_0067F1B0();
        func_003E51F8(p->unk64[0x27 + i]);
        func_L01_00516AA0(p->unk64[0x27 + i], 1, 0);
        func_L01_00516C78(p->unk64[0x27 + i], 3, 3);
        func_003E8630(D_L39_0024736C, p->unk64[0x27 + i]);
    }
}
/* localdecomp:end func_L39_00688460 */

/* localdecomp:start func_L39_006888B8 */
typedef struct {
    s32 off;
    s32 len;
} E_006888B8;
typedef struct {
    u8 pad0[0x4954];
    s32 base;
    E_006888B8 e[1];
} S_006888B8;
extern S_006888B8 D_001F0A00;
extern s32 D_L39_003D2880[];
extern s32 D_L39_0024737C;
__asm__(".extern D_L39_0024737C, 16");
extern s32 D_L39_00247520;
__asm__(".extern D_L39_00247520, 16");
extern u8 D_L39_00247A58[];
extern s32 D_L39_0024D7B0;
__asm__(".extern D_L39_0024D7B0, 32");
extern s32 D_001DBC6C_sda;
extern f32 D_001DC30C_sda;
__asm__(".extern D_001DC30C_sda, 4");
extern f32 D_001DC314_sda;
__asm__(".extern D_001DC314_sda, 4");
extern f32 D_001DC318_sda;
__asm__(".extern D_001DC318_sda, 4");
extern f32 D_001DC32C_sda;
__asm__(".extern D_001DC32C_sda, 4");
extern f32 D_001DC330_sda;
__asm__(".extern D_001DC330_sda, 4");
extern f32 D_001DC334_sda;
__asm__(".extern D_001DC334_sda, 4");
extern f32 D_001DC338_sda;
__asm__(".extern D_001DC338_sda, 4");
extern f32 D_001DC33C_sda;
__asm__(".extern D_001DC33C_sda, 4");
extern f32 D_001DC340_sda;
__asm__(".extern D_001DC340_sda, 4");
extern s32 func_L39_0067F0A0(void);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_003A26F0(s32, s32, s32);
extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);
extern void func_003E5360(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00120048(u8 *, u8 *, ...);

void func_L39_006888B8(void) {
    s32 i;
    s32 j;
    s32 s;

    D_L39_003D2880[4] = func_L39_0067F0A0();
    func_003E9138(D_L39_003D2880[4], 0, 0.5f, 0.5f, 1.999f, 1.0f, 0);
    func_003E87B8(D_L39_003D2880[4], 1, 8);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[4]);
    D_L39_003D2880[5] = func_L39_0067F0A0();
    func_003E9138(D_L39_003D2880[5], 0, 0.5f, 0.5f, 1.999f, 1.0f, 0);
    func_003E87B8(D_L39_003D2880[5], 1, 8);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[5]);
    s = D_001F0A00.e[func_L39_005B43C8(0x41, 0x46)].off + D_001F0A00.base;
    func_003A26F0(D_L39_00247520, s, D_001F0A00.e[func_L39_005B43C8(0x41, 0x46)].len);
    func_L39_005DBEE8(func_003B43B0(0), D_L39_00247520, 0);
    func_003E8710(D_L39_003D2880[4], func_003B43B0(0));
    func_003E8710(D_L39_003D2880[5], func_003B43B0(0));
    func_L01_00517190(D_L39_003D2880[4], 1);
    func_L01_00517190(D_L39_003D2880[5], 1);

    D_L39_003D2880[0xB] = func_L39_0067F0A0();
    func_003E9138(D_L39_003D2880[0xB], 0x331465B7, 0.5f, 0.5f, D_001DC334_sda, D_001DC338_sda, 0);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0xB]);
    D_L39_003D2880[0] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[0], 0x3D, 0x332299DE, D_001DC33C_sda, D_001DC340_sda, 1.0f, 1.0f, 0.62f);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0]);
    D_L39_003D2880[1] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[1], 0x3E, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.62f);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[1]);
    D_L39_003D2880[2] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[2], 0x3F, 0x331465B7, 0.5f, 0.5f, 1.0f, 1.0f, 0.62f);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[2]);
    D_L39_003D2880[3] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[3], 0x40, 0x802299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.62f);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[3]);
    D_L39_003D2880[8] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[8], 0x35, 0x331465B7, D_001DC33C_sda, D_001DC340_sda, 1.0f, 1.0f, D_001DC30C_sda);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[8]);
    D_L39_003D2880[9] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[9], 0x36, 0x802299DE, D_001DC33C_sda, D_001DC340_sda, 1.0f, 1.0f, D_001DC30C_sda);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[9]);
    D_L39_003D2880[6] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[6], 0x33, 0x332299DE, D_001DC33C_sda, D_001DC340_sda, 1.0f, 1.0f, D_001DC30C_sda);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[6]);
    D_L39_003D2880[7] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[7], 0x34, 0x332299DE, D_001DC33C_sda, D_001DC340_sda, 1.0f, 1.0f, D_001DC30C_sda);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[7]);
    D_L39_003D2880[0xA] = func_L39_0067F0A0();
    func_003E9270(D_L39_003D2880[0xA], 0x332299DE, D_001DC33C_sda, D_001DC340_sda, D_001DC334_sda, D_001DC338_sda, D_001DC314_sda, D_001DC318_sda);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0xA]);
    D_L39_003D2880[0x92] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[0x92], 0x66, 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f);
    func_L01_00516AA0(D_L39_003D2880[0x92], 1, 0);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x92]);
    D_L39_003D2880[0x93] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[0x93], 0x68, 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f);
    func_L01_00516AA0(D_L39_003D2880[0x93], 1, 0);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x93]);
    for (i = 0; i < 4; i++) {
        D_L39_003D2880[0x94 + i] = func_L39_0067F0A0();
        func_003E8EF0(D_L39_003D2880[0x94 + i], 0x69, 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f);
        func_L01_00516AA0(D_L39_003D2880[0x94 + i], 1, 0);
        func_003E8630(D_L39_0024737C, D_L39_003D2880[0x94 + i]);
    }

    D_L39_003D2880[0x15] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[0x15], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f);
    func_L01_00516AA0(D_L39_003D2880[0x15], 1, 0);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x15]);
    D_L39_003D2880[0x16] = func_L39_0067F0A0();
    func_003E8EF0(D_L39_003D2880[0x16], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, -1.0f, 0.5f);
    func_L01_00516AA0(D_L39_003D2880[0x16], 1, 0);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0x16]);
    D_L39_003D2880[0xC] = func_L39_0067F0A0();
    func_003E8FE8(D_L39_003D2880[0xC], func_00381FF0(0xFFF), 0x8066CCFF, 0.5f, 0.07f, 1.2f, 1.2f);
    func_L01_00516AA0(D_L39_003D2880[0xC], 0x40, 1);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0xC]);
    D_L39_003D2880[0xD] = func_L39_0067F0A0();
    func_003E8FE8(D_L39_003D2880[0xD], func_00381FF0(0x218), 0x8066CCFF, D_001DC330_sda, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(D_L39_003D2880[0xD], 0x40, 1);
    func_L01_00516C78(D_L39_003D2880[0xD], 3, 3);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0xD]);
    D_L39_003D2880[0xE] = func_L39_0067F0A0();
    func_003E8FE8(D_L39_003D2880[0xE], func_00381FF0(0xCD5), 0x8066CCFF, D_001DC32C_sda, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(D_L39_003D2880[0xE], 0x40, 1);
    func_L01_00516C78(D_L39_003D2880[0xE], 3, 3);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0xE]);
    D_L39_003D2880[0xF] = func_L39_0067F0A0();
    func_003E8FE8(D_L39_003D2880[0xF], func_00381FF0(0xCD5), 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(D_L39_003D2880[0xF], 0x40, 1);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0xF]);
    D_L39_003D2880[0x10] = func_L39_0067F0A0();
    func_003E5360(D_L39_003D2880[0x10]);
    func_00120048((u8 *)&D_L39_0024D7B0, D_L39_00247A58, func_00381FF0(0xF69));
    func_L01_00516470(D_L39_003D2880[0x10], 0.5f, 0.85f);
    func_L01_00516C78(D_L39_003D2880[0x10], 3, 3);
    func_L01_00516AA0(D_L39_003D2880[0x10], 0x40, 1);
    func_L01_005170B8(D_L39_003D2880[0x10], 0x80CCCCCC);
    func_L01_00518010(D_L39_003D2880[0x10], 1);
    func_003E8898(D_L39_003D2880[0x10], 0.8f, 0.0f);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x10]);
    D_L39_003D2880[0x12] = func_L39_0067F0A0();
    func_003E9138(D_L39_003D2880[0x12], 0x80000000, 0.5f, 0.93f, 0.5f, 0.055f, 0);
    func_L01_00516AA0(D_L39_003D2880[0x12], 1, 0);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x12]);
    D_L39_003D2880[0x13] = func_L39_0067F0A0();
    func_003E9270(D_L39_003D2880[0x13], 0x332299DE, 0.5f, 0.93f, 0.5f, 0.055f, 0.004f, 0.005f);
    func_L01_00516AA0(D_L39_003D2880[0x13], 1, 0);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0x13]);
    D_L39_003D2880[0x11] = func_L39_0067F0A0();
    func_003E8FE8(D_L39_003D2880[0x11], func_00381FF0(0xFE4), 0x8066CCFF, 0.5f, 0.93f, 0.6f, 1.0f);
    func_L01_00516AA0(D_L39_003D2880[0x11], 0x40, 1);
    func_L01_00516AA0(D_L39_003D2880[0x11], 1, 0);
    func_003E8630(D_001DBC6C_sda, D_L39_003D2880[0x11]);
    D_L39_003D2880[0x14] = func_L39_0067F0A0();
    func_003E51F8(D_L39_003D2880[0x14]);
    func_L01_00516AA0(D_L39_003D2880[0x14], 1, 0);
    func_L01_00516C78(D_L39_003D2880[0x14], 3, 3);
    func_003E8630(D_L39_0024737C, D_L39_003D2880[0x14]);
    for (i = 0; i < 75; i++) {
        D_L39_003D2880[0x17 + i] = func_L39_0067F0A0();
        func_003E51F8(D_L39_003D2880[0x17 + i]);
        func_L01_00516AA0(D_L39_003D2880[0x17 + i], 1, 0);
        func_L01_00516C78(D_L39_003D2880[0x17 + i], 3, 3);
        func_003E8630(D_L39_0024737C, D_L39_003D2880[0x17 + i]);
    }
    for (i = 0; i < 8; i++) {
        D_L39_003D2880[0x62 + i] = func_L39_0067F0A0();
        func_003E9270(D_L39_003D2880[0x62 + i], 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.05f, 0.05f);
        func_L01_00516AA0(D_L39_003D2880[0x62 + i], 1, 1);
        func_003E8630(D_L39_0024737C, D_L39_003D2880[0x62 + i]);
    }
    for (i = 0; i < 40; i++) {
        D_L39_003D2880[0x6A + i] = func_L39_0067F0A0();
        func_003E51F8(D_L39_003D2880[0x6A + i]);
        func_L01_00516AA0(D_L39_003D2880[0x6A + i], 1, 0);
        func_L01_00516C78(D_L39_003D2880[0x6A + i], 3, 3);
        func_003E8630(D_L39_0024737C, D_L39_003D2880[0x6A + i]);
    }
    for (j = 0x98; j < 0x9E; j++) {
        D_L39_003D2880[j] = 0;
    }
    func_L39_0068A9B8(0);
}
/* localdecomp:end func_L39_006888B8 */
