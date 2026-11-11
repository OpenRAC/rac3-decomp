#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003BE1C8 */
typedef struct { u8 p0[0x68]; u8 *f68; } O;
typedef struct { u8 p0[0x324]; s32 f324; s32 f328; u8 p32C[8]; s32 f334; u8 p338[0xC]; s32 f344; } P;
extern u8 *D_L01_001E001C_E1C8_a;
__asm__(".extern D_L01_001E001C_E1C8_a, 16");
extern u8 *D_L01_001E001C_E1C8_b;
__asm__(".extern D_L01_001E001C_E1C8_b, 16");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern s16 *D_L01_0021DE20[];
extern void func_L01_003BD608(void *, void *);

void func_L01_003BE1C8(O *a0, O *a1, s32 a2) {
    P *p = (P *)a0->f68;
    s16 *q;
    if (a1 != 0) {
        P *p1 = (P *)a1->f68;
        p->f324 = ((u8 *)a1 - D_L01_001E001C_E1C8_a) >> 8;
        p1->f344 = ((u8 *)a0 - D_L01_001E001C_E1C8_a) >> 8;
    }
    p->f328 = a2;
    q = D_L01_0021DE20[a2];
    while ((p->f328 & 0xFF) != 0xFF && p->f328 <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[p->f328])) {
        O *r = (O *)(D_L01_001E001C_E1C8_b + ((*(u16 *)q & 0x7FFF) << 8));
        q++;
        if (r == 0) break;
        ((P *)r->f68)->f334 = ((u8 *)a0 - D_L01_001E001C_E1C8_b) >> 8;
    }
    func_L01_003BD608(a0, p);
}
/* localdecomp:end func_L01_003BE1C8 */

/* localdecomp:start func_L01_003BE2B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE2B0;
extern V4_3BE2B0 D_L01_001E29C0;
extern f32 D_001DEA64_sda;
__asm__(".extern D_001DEA64_sda, 4");
extern void func_0043A778(void *, s32, void *);
extern void func_0040E620(void *dst, void *src, f32 s);
extern void func_003CCC20(f32, void *, void *, void *, void *);

void func_L01_003BE2B0(u8 *a0, void *a1) {
    V4_3BE2B0 v0;
    V4_3BE2B0 v10;
    V4_3BE2B0 v20;
    V4_3BE2B0 v30;
    u8 *p = *(u8 **)(a0 + 0x68);
    func_0043A778(a0, 12, &v0);
    func_0043A778(a0, 11, &v10);
    vec_sub_ba(&v20, &D_L01_001E29C0, &v10);
    func_0040E620(&v20, &v20, D_001DEA64_sda);
    vec_add_ba(&v20, &v20, &v10);
    vec_sub_ab(&v30, &v10, &v0);
    func_0040E620(&v30, &v30, 0.70000005f);
    func_003CCC20((f32)p[0x44], a0, &v20, &v30, a1);
}
/* localdecomp:end func_L01_003BE2B0 */
