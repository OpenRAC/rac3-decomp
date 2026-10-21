#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A6790.c's earlier functions (tools/port_from_us.py) */
extern void func_00121760();
extern void func_003A9CB8();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
typedef struct { s32 k, v; } E_3A6830;
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;
extern u8 *func_003AB218(u8 *);
typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D5C78;
extern u8 D_001D8370[], D_001D8380[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void func_003AB250();
extern void func_003AB428(u8 *, u8 *, s32);
extern void func_003AB458(void *, f32);
extern void func_003AAF00(void *, s32);
extern s32 func_003AAEB8(void *);
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391130();
extern void func_003911B8();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_003AC638(s32, s32, s32, f32, f32, f32, f32);
typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
extern S_225980_3A7090 D_00225900_003AC638;
extern s32 D_001D5C78;
extern s32 D_001D52F0;
extern s32 func_003A9CB0();
extern void func_003A9CA8(s32);
extern s32 func_003AAEA8();
extern void func_003873C0();
extern void func_003AA320_003AC638(s32, f32, f32, s32, f32, f32, f32);
typedef struct { s32 *p0; s32 *p4; u8 *p8; s32 *pC; u8 sub10[0x178]; s32 f188, f18C, f190; u8 p194[4]; s32 f198, f19C, f1A0, f1A4; f32 f1A8; u8 p1AC[4]; f32 f1B0; s32 f1B4; } O_A73A0;
extern f32 D_001D8434_003AC948;
extern f32 D_001D8438_003AC948;
extern void func_003AB458(void *, f32);

/* localdecomp:start func_003ACBB8 */
s32 func_003ACBB8() {
}
/* localdecomp:end func_003ACBB8 */

/* localdecomp:start func_003ACBC0 */
extern s32 func_003AC948(void *);

void func_003ACBC0(void *arg0) {
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003AC948(arg0);
            break;
        case 2:
            func_003ACBB8(arg0);
            break;
        }
        func_003AC940(arg0);
    }
}
/* localdecomp:end func_003ACBC0 */
