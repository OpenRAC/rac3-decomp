#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_00381FF0();
extern void func_003E6FF8(void *p);

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } E_3AF2C0;
extern f32 D_001D894C;
extern f32 D_001D8940;
extern f32 D_001D8944;
extern f32 D_001D8950;
extern f32 D_001D8958;
extern f32 D_001D8954;
extern f32 D_001D895C;
extern E_3AF2C0 D_00337640_003B4878[];
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8E38(s32, s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_00381FF0();
/* localdecomp:start func_003B4878 */
__asm__(".extern D_001D894C, 4");
__asm__(".extern D_001D8940, 4");
__asm__(".extern D_001D8944, 4");
__asm__(".extern D_001D8950, 4");
__asm__(".extern D_001D8958, 4");
__asm__(".extern D_001D8954, 4");
extern s32 func_003B5060(s32);
void func_003B4878(void) {
    f32 half = 0.5f;
    f32 one = 1.0f;
    f32 one2;
    f32 zero;
    s32 i, j;
    E_3AF2C0 *e;
    f32 y, step;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, half, half, one, one, D_001D894C);
    func_003E9138(0xD0028, 0x402299DE, 0, half, half, 0.333333f, 0.025f);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    for (i = 0; i < 5; i++) {
        if (D_00337640_003B4878[i].x4 == 0x169C) {
            func_003E9358(D_00337640_003B4878[i].x0, func_00381FF0(0x169C), 0x8066CCFF, 0.5f, 0.0f, 0.465f, 0.078f, 1.0f);
            func_003E7838(D_00337640_003B4878[i].x0, 0x40, 1);
            func_003E8E38(D_00337640_003B4878[i].x0, 1, 1);
        } else {
            zero = 0.0f;
            one2 = 1.0f;
            func_003E8FE8(D_00337640_003B4878[i].x0, func_00381FF0(D_00337640_003B4878[i].x4), 0x8066CCFF, zero, zero, one2, one2);
            func_003E7838(D_00337640_003B4878[i].x0, 0x40, 1);
            func_003E8898(D_00337640_003B4878[i].x0, 0.425f, 0.85f);
            func_003E8958(D_00337640_003B4878[i].x0, 1);
        }
        func_003E8630(0xD0025, D_00337640_003B4878[i].x0);
    }
    func_003E8348(0x11, 0xD0025);
    {
    s32 id = 0x169C;
    step = D_001D8940;
    y = D_001D8944;
    for (i = 4, j = 0; i >= 0; i--, j++) {
        if (D_00337640_003B4878[j].x4 == id) y = 0.558f;
        func_003E73B8(D_00337640_003B4878[j].x0, 0.5f, y);
        if (D_00337640_003B4878[j].x4 == id) y = 0.647f;
        else y += step;
    }
    }
    func_003E9138(0x5B0000, 0x332299DE, 0xED5A, D_001D8950, D_001D8958, -0.07f, 0.08615385f);
    func_003E9138(0x5B0001, 0x332299DE, 0xED5A, D_001D8954, D_001D895C, 0.07f, -0.08615385f);
    func_003E8A08(0xD000B, 0x5B0000, 0x5B0001);
    for (i = 0; i < 4; i++) {
        func_003E9138(i + 0x5B0002, 0x331465B7, 0, 0.5f, 0.2f, 0.33f, 0.006667f);
        func_003E8630(0xD000B, i + 0x5B0002);
    }
}
/* localdecomp:end func_003B4878 */

typedef struct { s32 x0; s32 x4; u8 b8; u8 p9[3]; void (*fnC)(void); } E_3AF718;
extern f32 D_001D8960[2];
extern f32 D_001D8970;
extern s32 D_001D8948;
extern s32 D_001DA13C;
extern s32 D_001DA144;
extern f32 D_001DA138;
extern f32 D_001DA140;
extern f32 D_001D8944;
extern f32 D_001D8940;
extern f32 D_001D8974;
extern f32 D_001D8978;
extern f32 D_001D8998[2];
extern f32 D_001D8980[2];
extern u8 *D_001D52FC_003B4CD0;
extern E_3AF718 D_00337640[];
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7D70(s32, s32);
extern void func_003A5348();
extern s32 func_003BB0C0();
extern void func_003BB0C8();
extern void func_003E6FF8(void *p);
extern void func_003BB5D0();
extern void func_003BB590(s32);
/* localdecomp:start func_003B4CD0 */
__asm__(".extern D_001D8960, 8");
__asm__(".extern D_001D8970, 4");
__asm__(".extern D_001D8948, 4");
__asm__(".extern D_001DA13C, 4");
__asm__(".extern D_001DA144, 4");
__asm__(".extern D_001DA138, 4");
__asm__(".extern D_001DA140, 4");
__asm__(".extern D_001D8944, 4");
__asm__(".extern D_001D8940, 4");
__asm__(".extern D_001D8974, 4");
__asm__(".extern D_001D8978, 4");
__asm__(".extern D_001D8998, 8");
__asm__(".extern D_001D8980, 8");
void func_003B4CD0(void *arg0) {
    s32 i;
    s32 t;
    s32 found;
    for (i = 0; i < 4; i++) {
        func_003E73B8(i + 0x5B0002, 0.5f, D_001D8960[i]);
        func_003E81F0(i + 0x5B0002, D_001D8970, 0.006667f);
    }
    t = *(s32 *)(D_001D52FC_003B4CD0 + 0x1C4);
    if (t & 0x4000) {
        found = 0;
        do {
            D_001D8948++;
            if (D_001D8948 >= 5) D_001D8948 = 0;
            if (D_00337640[D_001D8948].b8) found = 1;
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (t & 0x1000) {
        found = 0;
        do {
            D_001D8948--;
            if (D_001D8948 < 0) D_001D8948 = 4;
            if (D_00337640[D_001D8948].b8) found = 1;
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (t & 0x40) {
        if (D_00337640[D_001D8948].b8 && D_00337640[D_001D8948].fnC) {
            D_00337640[D_001D8948].fnC();
            func_003A5348(4, 0, 0);
        }
    } else if (!(t & 0x910)) {
        if (func_003BB0C0()) {
            func_003BB0C8();
            func_003E6FF8(arg0);
        }
    }
    if (D_001DA13C == 0) {
        D_001DA13C = 1;
        D_001DA138 = D_001D8944;
    }
    if (D_001DA144 == 0) {
        D_001DA144 = 1;
        D_001DA140 = D_001D8940;
    }
    func_003E81F0(0xD0028, D_001D8974, D_001D8998[D_001D8948]);
    func_003E73B8(0xD0028, D_001D8978, D_001D8980[D_001D8948]);
    for (i = 0; i < 5; i++) {
        if (D_00337640[i].b8) {
            func_003E7D70(D_00337640[i].x0, 0x8066CCFF);
            if (i == D_001D8948) func_003E7D70(D_00337640[i].x0, 0x66D6EEFA);
        } else {
            func_003E7D70(D_00337640[i].x0, 0x80808080);
        }
    }
    func_003BB5D0();
    func_003BB590(0xD0028);
}
/* localdecomp:end func_003B4CD0 */
