#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_003BE2B0);
