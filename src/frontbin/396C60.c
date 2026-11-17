#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00396C60();
extern void func_003970D8();
typedef struct {
    u8 f0;
    u8 p1[0x37];
    u16 f38;
    u8 p3A[0x50];
    u16 f8A;
    u8 p8C[0xF0 - 0x8C];
} S_391E78;
typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;


typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400;
extern P_392108 *D_001D9EA8_00396C60;
extern W_392400 *D_001D9EAC_00396C60;
extern u32 *D_001DA050;
extern s32 func_00396A38_00396C60();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
/* localdecomp:start func_00396C60 */
extern u8 D_001D5EA4_00396C60;
extern s32 D_001D5E98_00396C60;
extern s32 D_001D5E9C_00396C60;
extern s32 D_001D5EA0_00396C60;
extern u8 D_001A4BE0_00396C60[];
extern u8 D_001425C0_00396C60[];
extern s32 D_001427F0_00396C60[];
extern S_391E78 D_001DAA40_00396AB8[];
extern s32 func_00396A70(void);
extern void func_00393990(s32 id, s32 v);
extern void func_00396770();
extern void func_00397EF0();
extern s32 func_003967A0(void);
extern void func_00393CD8();
extern s32 func_00396658();
typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8_00396C60;
extern S_391FD8_00396C60 D_00331AE0_00396C18[];
extern s32 D_001D9EC0_00396C60;
extern s32 D_001D9BDC_00396C60;
extern s32 D_001D9E94_00396C60;
extern s32 D_001D9DF8_00396C60;
extern s32 D_001D9DFC_00396C60;
extern s32 D_001D9E00_00396C60;
extern s32 D_001D5B94_00396C60;
typedef struct { s16 a; s16 b; } P_392108_00396C60;
typedef struct { s32 w; s32 pad; } W_392108_00396C60;
extern u8 D_001D5EA5_00396C60;
extern P_392108_00396C60 *D_001D9EA8_00396C60b[];
extern W_392108_00396C60 *D_001D9EAC_00396C60b[];
extern W_392108_00396C60 *D_001D9EB0_00396C60[];

typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400_00396C60;
extern P_392108_00396C60 *D_001D9EA8_00396C60_00396C60;
extern W_392400_00396C60 *D_001D9EAC_00396C60_00396C60;
extern u32 *D_001DA050_00396C60;
extern s32 func_00396A38_00396C60_00396C60();
extern s32 D_001D4BD0_00396C60;
extern s32 D_001D4BD4_00396C60;
extern s32 D_001D9E94_00396C60;
void func_00396C60(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 col) {
    unsigned long *q;
    P_392108_00396C60 *p = (P_392108_00396C60 *)((idx << 2) + (s32)D_001D9EA8_00396C60_00396C60);
    W_392400_00396C60 *e = &D_001D9EAC_00396C60_00396C60[p->b];
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    D_001DA050_00396C60[0] = 0x10000005;
    D_001DA050_00396C60[1] = 0;
    D_001DA050_00396C60[2] = 0;
    D_001DA050_00396C60[3] = 0x50000005;
    q = (unsigned long *)(D_001DA050_00396C60 + 4);
    D_001DA050_00396C60 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_00396A38_00396C60_00396C60(idx);
    q[3] = 0x156;
    q[4] = ((long)col << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0_00396C60 - 8) | ((long)(y * 16 + D_001D4BD4_00396C60 - 8) << 16)) | ((long)D_001D9E94_00396C60 << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0_00396C60 - 8) | ((long)((y + h) * 16 + D_001D4BD4_00396C60 - 8) << 16)) | ((long)D_001D9E94_00396C60 << 32);
    q[9] = 0;
    D_001DA050_00396C60 += 0x14;
}
/* localdecomp:end func_00396C60 */

typedef int u128_3925F0 __attribute__((mode(TI)));
extern u8 D_001D76F0[];
extern P_392108 *D_001D9EA8_00396E50;
extern W_392108 *D_001D9EAC_00396E50;
extern s32 D_001DA050_00396E50;
extern s32 D_001D9E94;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern unsigned long func_00396A38(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00396E50);

extern u32 *D_001DA050;
extern s32 func_00396A38_003970D8();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
/* localdecomp:start func_003970D8 */
extern u32 *D_001DA050_003970D8;
extern s32 func_00396A38_003970D8_003970D8();
extern s32 D_001D4BD0_003970D8;
extern s32 D_001D4BD4_003970D8;
extern s32 D_001D9E94_003970D8;
void func_003970D8(s32 tex, s32 x, s32 y, s32 w, s32 h, s32 alpha) {
    unsigned long *q;
    D_001DA050_003970D8[0] = 0x10000005;
    D_001DA050_003970D8[1] = 0;
    D_001DA050_003970D8[2] = 0;
    D_001DA050_003970D8[3] = 0x50000005;
    q = (unsigned long *)(D_001DA050_003970D8 + 4);
    D_001DA050_003970D8 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_00396A38_003970D8_003970D8(tex);
    q[3] = 0x156;
    q[4] = ((long)alpha << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0_003970D8 - 8) | ((long)(y * 16 + D_001D4BD4_003970D8 - 8) << 16)) | ((long)D_001D9E94_003970D8 << 32);
    q[7] = (h << 20) + (w << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0_003970D8 - 8) | ((long)((y + h) * 16 + D_001D4BD4_003970D8 - 8) << 16)) | ((long)D_001D9E94_003970D8 << 32);
    q[9] = 0;
    D_001DA050_003970D8 += 0x14;
}
/* localdecomp:end func_003970D8 */
