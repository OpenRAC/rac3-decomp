#include "common.h"

/* localdecomp:start func_L39_00578048 */
typedef struct E_00578048 {
    u8 pad0[0x188];
    u8 f188;
    u8 f189;
    u8 pad1[0x558 - 0x18A];
    u8 f558;
    u8 pad2[0x5C0 - 0x559];
} E_00578048;
typedef struct R_00578048 {
    s32 v;
    u8 b;
} R_00578048;
__asm__(".extern D_L39_00225780, 16");
extern E_00578048 D_L39_00225780[8];
extern u8 D_001A58BE[];
__asm__(".extern D_001D6C58_sda, 4");
extern s32 D_001D6C58_sda;
extern s32 func_L01_003F22D8(R_00578048 *, E_00578048 *);

void func_L39_00578048(void)
{
    s32 i;
    s32 *q = &D_001D6C58_sda;
    for (i = 0; i < 8; i++) {
        E_00578048 *p = &D_L39_00225780[i];
        if (p->f558 != 0) {
            R_00578048 r;
            func_L01_003F22D8(&r, p);
            if (D_001A58BE[i] != 0) {
                s32 s = q[i] + r.v;
                q[i] = s;
                if (s >= 0x100) {
                    p->f188 = 1;
                    q[i] = s - 0xFF;
                } else {
                    p->f188 = 0;
                }
                p->f189 = r.b;
            }
        } else {
            p->f188 = 0;
            p->f189 = 0;
        }
    }
}
/* localdecomp:end func_L39_00578048 */

INCLUDE_ASM("asm/levels", func_L39_00578118);

/* localdecomp:start func_L39_005782F0 */
__asm__(".extern D_001FC48C, 16");
__asm__(".extern D_L39_00240460, 16");
typedef struct { char pad[0x64C]; int base; int offset; int count; } S_5782F0;
extern S_5782F0 D_001F0A00;
extern char D_L39_00269500[];
extern int D_001FC48C[];
extern long D_L39_00240460;
extern int func_003A26F0(char *, int, int);
extern void func_L39_00578118(char *, long *, int, int);

/* from rac2-decomp's func_0026FE48 */
void func_L39_005782F0(void)
{
    long local[4];
    char *data = D_L39_00269500;
    func_003A26F0(data, D_001F0A00.offset + D_001F0A00.base, D_001F0A00.count);
    func_L39_00578118(data, local, D_001FC48C[0], 0x3FFC00);
    D_L39_00240460 = local[0];
}
/* localdecomp:end func_L39_005782F0 */
