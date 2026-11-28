/* func_L39_006B9008, wave 13 (r29): first plain-C draft (fresh entry), 59 diff positional under its file's line
 * (wave10/p10/check.py, first placement; 32 words when aligned, same 977-word length). Written unrolled as retail
 * is, through inline widget helpers (base: kind 0 then the func_L39_0068CD28 call; row kind 1; text kind 8 with
 * its 0x48/0x110/0x114-0x116 fields; quad kind 0xC with 0xED26, 0.0/1.0 and 0x706EC8FF; root 0x2E with 96
 * slots): twelve 0x50 rows (row 0 titled 0x10ED at x = D_001DDC54_sda), eleven 0x120 text widgets, four 0x60
 * quads ((T + 0.01) * 0.0/1.0/2.0/3.0) and the 27-item root, every layout float re-read from its gp slot per
 * widget. The helpers matter: their parameter copies keep cc1 from sharing the 0.05f height in a callee-saved
 * register (retail loads it into f15 at each call) and give retail's stores through the widget pointer.
 * Still differs: the callee-saved registers of the last text widgets and quads (retail big7 = s3, big8..quad1 =
 * fp, s7, s6, s5, s4; here fp, s7, s6, s5, s4, s3) and the reload of self (lw a0,0x1370(sp)) for the final
 * call, which retail schedules after the twelfth item store. */
#include "common.h"

/* localdecomp:start func_L39_006B9008 */
typedef struct { s32 kind; u8 name[0x34]; f32 x; f32 y; f32 w; f32 h; } B_006B9008;
typedef struct { B_006B9008 b; u8 pad48[8]; } Row_006B9008;
typedef struct { B_006B9008 b; u8 f48; u8 pad49[0xC7]; s32 f110; u8 f114; u8 f115; u8 f116; u8 pad117[9]; } Big_006B9008;
typedef struct { B_006B9008 b; f32 f48; f32 f4C; f32 f50; f32 f54; s32 f58; s32 f5C; } Quad_006B9008;
typedef struct { B_006B9008 b; s32 f48; s32 count; void *items[96]; } Root_006B9008;

extern u8 D_L39_0047E780[];
__asm__(".extern D_001DDC54_sda, 4");
extern f32 D_001DDC54_sda;
__asm__(".extern D_001DDC58_sda, 4");
extern f32 D_001DDC58_sda;
__asm__(".extern D_001DDC5C_sda, 4");
extern f32 D_001DDC5C_sda;
__asm__(".extern D_001DDC60_sda, 4");
extern f32 D_001DDC60_sda;
__asm__(".extern D_001DDC64_sda, 4");
extern f32 D_001DDC64_sda;
__asm__(".extern D_001DDC68_sda, 4");
extern f32 D_001DDC68_sda;
__asm__(".extern D_001DDC6C_sda, 4");
extern f32 D_001DDC6C_sda;
__asm__(".extern D_001DDC70_sda, 4");
extern f32 D_001DDC70_sda;
__asm__(".extern D_001DDC74_sda, 4");
extern f32 D_001DDC74_sda;
__asm__(".extern D_001DDC78_sda, 4");
extern f32 D_001DDC78_sda;
__asm__(".extern D_001DDC7C_sda, 4");
extern f32 D_001DDC7C_sda;
__asm__(".extern D_001DDC90_sda, 4");
extern u8 D_001DDC90_sda[] __attribute__((section(".sdata")));
extern void func_L39_0068CD28(void *, u8 *, f32, f32, f32, f32);

static __inline__ void base_006B9008(B_006B9008 *p, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    p->kind = 0;
    func_L39_0068CD28(p, text, x, y, w, h);
}

static __inline__ void row_006B9008(Row_006B9008 *p, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 1;
}

static __inline__ void big_006B9008(Big_006B9008 *p, u8 *text, f32 x, f32 y, f32 w, f32 h, s32 a, s32 b, s32 n) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 8;
    p->f48 = 0;
    p->f114 = a;
    p->f110 = n;
    p->f115 = b;
    p->f116 = 0;
}

static __inline__ void quad_006B9008(Quad_006B9008 *p, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, D_001DDC90_sda, x, y, w, h);
    p->b.kind = 0xC;
    p->f58 = 0xED26;
    p->f48 = 0.0f;
    p->f50 = 0.0f;
    p->f4C = 1.0f;
    p->f54 = 1.0f;
    p->f5C = 0x706EC8FF;
}

static __inline__ void root_006B9008(Root_006B9008 *p) {
    base_006B9008(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->f48 = 0x2E;
    p->count = 0;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
}

void *func_L39_006B9008(u8 *self) {
    extern void func_L39_00688388(void *);
    extern u8 *func_00381FF0(s32);
    extern void func_L39_00689670(void *, void *);
    Row_006B9008 row[12];
    Big_006B9008 big[11];
    Quad_006B9008 quad[4];
    Root_006B9008 root;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047E780;
    *(u8 **)(self + 0x2A4) = self + 0x2B4;
    row_006B9008(&row[0], func_00381FF0(0x10ED), D_001DDC54_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -5.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[1], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -4.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[2], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -3.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[3], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -2.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[4], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -1.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[5], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -0.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[6], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 0.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[7], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 1.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[8], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 2.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[9], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 3.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[10], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 4.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    row_006B9008(&row[11], D_001DDC90_sda, D_001DDC54_sda - D_001DDC5C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 5.5f / 12.0f,
                 D_001DDC5C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f);
    big_006B9008(&big[0], func_00381FF0(0xF8A), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -5.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[1], func_00381FF0(0x10FC), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -4.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[2], func_00381FF0(0x1322), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -3.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[3], func_00381FF0(0x1101), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -2.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[4], func_00381FF0(0x160B), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -1.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[5], func_00381FF0(0x12A4), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 0.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[6], func_00381FF0(0x1334), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 1.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[7], func_00381FF0(0x1335), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 2.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[8], func_00381FF0(0x1336), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 3.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[9], func_00381FF0(0x1337), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 4.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    big_006B9008(&big[10], func_00381FF0(0x133E), D_001DDC64_sda - D_001DDC6C_sda * 0.5f + D_001DDC74_sda,
                 D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * 5.0f / 11.0f,
                 D_001DDC6C_sda - (D_001DDC74_sda + D_001DDC74_sda), 0.05f, 0, 0, 0x20);
    quad_006B9008(&quad[0],
                  D_001DDC64_sda + (D_001DDC6C_sda * 0.5f - D_001DDC74_sda - D_001DDC78_sda * 0.5f) - (D_001DDC78_sda + 0.01f) * 0.0f,
                  D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -1.0f / 11.0f, D_001DDC78_sda, D_001DDC7C_sda);
    quad_006B9008(&quad[1],
                  D_001DDC64_sda + (D_001DDC6C_sda * 0.5f - D_001DDC74_sda - D_001DDC78_sda * 0.5f) - (D_001DDC78_sda + 0.01f) * 1.0f,
                  D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -1.0f / 11.0f, D_001DDC78_sda, D_001DDC7C_sda);
    quad_006B9008(&quad[2],
                  D_001DDC64_sda + (D_001DDC6C_sda * 0.5f - D_001DDC74_sda - D_001DDC78_sda * 0.5f) - (D_001DDC78_sda + 0.01f) * 2.0f,
                  D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -1.0f / 11.0f, D_001DDC78_sda, D_001DDC7C_sda);
    quad_006B9008(&quad[3],
                  D_001DDC64_sda + (D_001DDC6C_sda * 0.5f - D_001DDC74_sda - D_001DDC78_sda * 0.5f) - (D_001DDC78_sda + 0.01f) * 3.0f,
                  D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -1.0f / 11.0f, D_001DDC78_sda, D_001DDC7C_sda);
    root_006B9008(&root);
    root.count = 27;
    root.items[0] = &row[0];
    root.items[1] = &row[1];
    root.items[2] = &row[2];
    root.items[3] = &row[3];
    root.items[4] = &row[4];
    root.items[5] = &row[5];
    root.items[6] = &row[6];
    root.items[7] = &row[7];
    root.items[8] = &row[8];
    root.items[9] = &row[9];
    root.items[10] = &row[10];
    root.items[11] = &row[11];
    root.items[12] = &big[0];
    root.items[13] = &big[1];
    root.items[14] = &big[2];
    root.items[15] = &big[3];
    root.items[16] = &big[4];
    root.items[17] = &big[5];
    root.items[18] = &big[6];
    root.items[19] = &big[7];
    root.items[20] = &big[8];
    root.items[21] = &big[9];
    root.items[22] = &big[10];
    root.items[23] = &quad[0];
    root.items[24] = &quad[1];
    root.items[25] = &quad[2];
    root.items[26] = &quad[3];
    func_L39_00689670(self, &root);
    return self;
}
/* localdecomp:end func_L39_006B9008 */
