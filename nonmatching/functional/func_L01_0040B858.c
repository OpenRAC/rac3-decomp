/* functional: high. Written from the PAL asm (the NTSC-U draft in nonmatching/levels differs: PAL computes ((1/x)*5+2)/6 args and divides by them, not 1/p). Instruction mix equals retail except the div.s nops (48 vs 20 nops: needs a divs_nops line) and a movn for the default-params select. Vector ops are plain C (xyz only, w from the first operand) so no asm; formerly needed -mvu0-use-vf0-vf2 on the file flags for the vec helpers. */
#include "vu0.h"
/* plain-C stand-ins for the vector library's vsub.xyz/vadd.xyz: x/y/z of a op b, w kept from a */
static void fvsub3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x - ((vu0_v4 *)b)->x;
    r.y = r.y - ((vu0_v4 *)b)->y;
    r.z = r.z - ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
static void fvadd3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x + ((vu0_v4 *)b)->x;
    r.y = r.y + ((vu0_v4 *)b)->y;
    r.z = r.z + ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
typedef struct {
    vu0_v4 from;
    vu0_v4 to;
    s32 state;
    s32 time;
} Line_0040B858;
typedef struct {
    s32 fadein, fadeout;
    f32 fade;
    s32 a, b;
    f32 width, widthScale, first;
    f32 p0, p1, p2, p3, step;
    s32 count;
    char pad[8];
    void *a40, *a44, *a48;
    s32 texture;
} Params_0040B858;
typedef struct {
    f32 *p0, *p1, *dir;
    f32 length, lo, hi;
    f32 *c0, *c1, *c2, *c3;
    s32 col0, col1;
} Draw_0040B858;
extern Params_0040B858 D_L01_002C54B0;
extern s32 D_L01_001DFB40;
extern s32 D_001DFB40_sda;
__asm__(".extern D_001DFB40_sda, 4");
extern s32 D_001D6430_sda;
__asm__(".extern D_001D6430_sda, 4");
extern s32 D_001D6450_sda;
__asm__(".extern D_001D6450_sda, 4");
extern s32 D_001D6410_sda;
__asm__(".extern D_001D6410_sda, 4");
extern vu0_v4 D_L01_001E29C0;
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_0040F518(f32, f32);
extern void func_003A9440(s32 a0, long a1);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_L01_0040B3C0(Params_0040B858 *, Draw_0040B858 *);
void func_L01_0040B858(Line_0040B858 *line, Params_0040B858 *p) {
    vu0_v4 dir, view, cross, from, to;
    Draw_0040B858 draw;
    f32 vals[4];
    f32 wide, firstWide, total, current, seg, end, one, r;
    s32 elapsed;
    if (line->state == 0) {
        return;
    }
    if (p == 0) {
        p = &D_L01_002C54B0;
    }
    if (line->state == 2) {
        elapsed = D_L01_001DFB40 - line->time;
        if (elapsed >= p->fadeout) {
            line->time = 0;
            line->state = 0;
            return;
        }
        wide = 1.0f - (f32)elapsed / (f32)p->fadeout;
    } else if (line->time > 0) {
        elapsed = D_001DFB40_sda - line->time;
        if (elapsed < p->fadein) {
            wide = (f32)elapsed / (f32)p->fadein * p->fade;
        } else {
            line->time = 0;
            wide = 1.0f;
        }
    } else {
        wide = 1.0f;
    }
    wide = wide * p->width;
    fvsub3_L01(&dir, &line->to, &line->from);
    one = 1.0f;
    firstWide = wide * p->widthScale;
    total = func_0038CEA8(&dir);
    current = 0.0f;
    func_0038CF68(&dir, &dir, one);
    fvsub3_L01(&view, &D_L01_001E29C0, &line->from);
    func_0038CE90(&cross, &view, &dir);
    func_0038CF68(&cross, &cross, one);
    if (p->a40 == 0) {
        p->a40 = &D_001D6430_sda;
    }
    if (p->a44 == 0) {
        p->a44 = &D_001D6450_sda;
    }
    if (p->a48 == 0) {
        p->a48 = &D_001D6410_sda;
    }
    r = func_L01_0040F518((f32)D_L01_001DFB40, (one / p->p0 * 5.0f + 2.0f) / 6.0f);
    r = r / ((one / p->p0 * 5.0f + 2.0f) / 6.0f) - 8.0f;
    vals[1] = r;
    r = func_L01_0040F518((f32)D_L01_001DFB40, (one / p->p1 * 5.0f + 2.0f) / 6.0f);
    r = r / ((one / p->p1 * 5.0f + 2.0f) / 6.0f) - 8.0f;
    vals[0] = r;
    r = func_L01_0040F518((f32)D_L01_001DFB40, (one / (p->p0 * p->p2) * 5.0f + 2.0f) / 6.0f);
    r = r / ((one / (p->p0 * p->p2) * 5.0f + 2.0f) / 6.0f) - 8.0f;
    vals[3] = r;
    r = func_L01_0040F518((f32)D_L01_001DFB40, (one / (p->p1 * p->p3) * 5.0f + 2.0f) / 6.0f);
    r = r / ((one / (p->p1 * p->p3) * 5.0f + 2.0f) / 6.0f) - 8.0f;
    vals[2] = r;
    draw.p0 = (f32 *)&from;
    draw.p1 = (f32 *)&to;
    draw.dir = (f32 *)&cross;
    draw.lo = wide;
    draw.hi = wide;
    draw.c0 = &vals[0];
    draw.c1 = &vals[1];
    draw.c2 = &vals[2];
    draw.c3 = &vals[3];
    draw.col0 = p->a;
    draw.col1 = p->b;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1UL);
    func_003A9440(6, func_00389598(p->texture));
    func_0038C750();
    seg = p->first;
    if (current < seg) {
        if (total < seg) {
            seg = total;
        }
        from = line->from;
        func_0038CE20((f32 *)&to, (f32 *)&dir, seg);
        current = seg + current;
        fvadd3_L01(&to, &to, &line->from);
        draw.lo = firstWide;
        draw.length = seg;
        func_L01_0040B3C0(p, &draw);
        draw.lo = wide;
    }
    end = total - 0.05f;
    while (current < end) {
        seg = total - current;
        if (p->step * (f32)p->count < seg) {
            seg = p->step * (f32)p->count;
        }
        func_0038CE20((f32 *)&from, (f32 *)&dir, current);
        r = current + seg;
        fvadd3_L01(&from, &from, &line->from);
        func_0038CE20((f32 *)&to, (f32 *)&dir, r);
        current = r;
        fvadd3_L01(&to, &to, &line->from);
        draw.length = seg;
        func_L01_0040B3C0(p, &draw);
    }
    func_003A9440(0x47, 0x5360BUL);
}
