#include "common.h"

/* localdecomp:start func_L01_00431810 */
typedef struct {
    u8 pad[0x464];
    u8 spent[1];
} S_00431810;

extern s32 D_L01_001D7278[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7278, 4");
extern s32 D_L01_001D728C;
__asm__(".extern D_L01_001D728C, 4");
extern u8 D_L01_001D7294;
__asm__(".extern D_L01_001D7294, 1");
extern u8 D_L01_001D7298;
__asm__(".extern D_L01_001D7298, 1");
extern u8 D_L01_001D729C;
__asm__(".extern D_L01_001D729C, 1");
extern u8 D_L01_001D72A0;
__asm__(".extern D_L01_001D72A0, 1");
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern S_00431810 D_L01_00237800;
extern u8 D_001BBE90[];
extern void func_L01_004316B0(f32 *a, f32 *b, s32 idx, s32 m, f32 x, f32 y);
extern s32 func_00396968(s32, s32);
extern void func_L01_004208E0(int idx, int x, int y, int w, int h, int a, unsigned int col);

void func_L01_00431810(f32 x0, f32 x1, f32 y0, f32 y1, f32 scale) {
    s32 *list = D_L01_001D7278;
    f32 pos[2];
    s32 i;
    u8 *m;
    s16 o;
    u16 id;
    s32 b;
    f32 sz;
    f32 size;
    s32 tex;

    D_L01_001D7294 = D_L01_001D72A0 ? D_L01_001D7294 + D_L01_001D7298 : D_L01_001D7294 - D_L01_001D729C;
    if (D_L01_001D7294 < 0x60 || D_L01_001D7294 > 0xF0) {
        D_L01_001D72A0 ^= 1;
        if (D_L01_001D7294 > 0xF0) {
            D_L01_001D7294 = 0xF0;
        }
        if (D_L01_001D7294 < 0x30) {
            D_L01_001D7294 = 0x30;
        }
    }

    size = 96.0f;
    for (i = 0; list[i] != 0 && i < 10; i++) {
        for (m = D_L01_001E001C; m < D_L01_001E0020; m += 0x100) {
            if (m == 0) continue;
            o = *(s16 *)(m + 0xAA);
            if (o != list[i]) continue;
            if (m[0x20] == 0xFE) continue;
            if (m[0x20] == 0xFD) continue;
            if (((o == 0x199F || o == 0x19C2) &&
                 !(id = *(u16 *)(m + 0xB2), D_L01_00237800.spent[(s16)id] ||
                   (b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], (id & 1) ? (b >> 4) & 7 : b & 7))) ||
                (list[i] != 0x199F && list[i] != 0x19C2)) {
                ((void (*)(f32 *, f32 *, f32, f32, s32, s32))func_L01_004316B0)(&pos[0], &pos[1], *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), D_001D545C, -1);
            }
            sz = scale * size;
            pos[0] = x0 + pos[0] * (x1 - x0);
            pos[1] = y0 + pos[1] * (y1 - y0);
            pos[0] -= sz * 0.5f;
            pos[1] -= sz * 0.5f;
            tex = func_00396968(0xEAA2, 1);
            func_L01_004208E0(tex, pos[0], pos[1], sz + 24.0f, sz + 24.0f, D_L01_001D7294, 0x80000000);
            func_L01_004208E0(func_00396968(0xEAA2, 1), pos[0], pos[1], sz, sz, D_L01_001D7294, D_L01_001D728C);
        }
    }
}
/* localdecomp:end func_L01_00431810 */

/* localdecomp:start func_L01_00431B58 */
typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
} S_00431B58;

extern s32 D_L01_001D72A8[] __attribute__((section(".sdata")));
extern s32 D_L01_001D72B8[] __attribute__((section(".sdata")));
extern s32 D_L01_001D7290;
__asm__(".extern D_L01_001D72A8, 4");
__asm__(".extern D_L01_001D72B8, 4");
__asm__(".extern D_L01_001D7290, 4");
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern u32 D_00142BA0[];
extern u8 D_00142CA0[];
extern S_00431B58 D_L01_001F3F40;
extern u8 D_L01_001F3F60[][16];
extern s32 func_L01_0040F5B8(void *, void *, void *);
extern s32 func_L01_00430460(void *, s32);
extern void func_L01_004316B0(f32 *a, f32 *b, s32 idx, s32 m, f32 x, f32 y);
extern s32 func_00396968(s32, s32);
extern void func_L01_004208E0(int idx, int x, int y, int w, int h, int a, unsigned int col);

void func_L01_00431B58(f32 x0, f32 x1, f32 y0, f32 y1, f32 scale) {
    f32 pos[2];
    s32 i;
    s32 j;
    s32 r;
    u8 *m;
    f32 sz;
    s32 tex;

    i = 0;
    if (D_L01_001D72A8[0] != 0) do {
        if (D_001D545C == 3 && D_L01_001D72A8[i] == 11) {
            continue;
        }
        for (m = D_L01_001E001C; m < D_L01_001E0020; m += 0x100) {
            if (m == 0) continue;
            if (*(s16 *)(m + 0xAA) != D_L01_001D72A8[i]) continue;
            if (m[0x20] == 0xFE) continue;
            if (m[0x20] == 0xFD) continue;
            if (*(s16 *)(m + 0xAA) == 11) {
                if (!func_L01_00430460(m + 0x10, 1) && !D_00142CA0[5]) continue;
            } else if (*(s16 *)(m + 0xAA) == 0x1F28) {
                if (!(D_00142BA0[0x25] & 0x200000) && !D_00142CA0[5]) continue;
            }
            r = 0;
            for (j = D_L01_001F3F40.count - 1; j >= 0; j--) {
                if (func_L01_0040F5B8(m + 0x10, D_L01_001F3F60[j], D_L01_001F3F60[j + 2])) {
                    r = j + 1;
                    break;
                }
            }
            func_L01_004316B0(&pos[0], &pos[1], D_001D545C, r, *(f32 *)(m + 0x10), *(f32 *)(m + 0x14));
            pos[0] = x0 + pos[0] * (x1 - x0);
            pos[1] = y0 + pos[1] * (y1 - y0);
            pos[0] -= scale * 64.0f;
            pos[1] -= scale * 64.0f;
            tex = func_00396968(0xE99A, D_L01_001D72B8[i]);
            sz = scale * 128.0f;
            func_L01_004208E0(tex, pos[0], pos[1], sz + 24.0f, sz + 24.0f, 100, 0x80000000);
            func_L01_004208E0(func_00396968(0xE99A, D_L01_001D72B8[i]), pos[0], pos[1], sz, sz, 100, D_L01_001D7290);
        }
    } while (D_L01_001D72A8[++i] != 0 && i < 10);
}
/* localdecomp:end func_L01_00431B58 */
