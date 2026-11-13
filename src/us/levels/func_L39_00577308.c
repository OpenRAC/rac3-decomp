#include "common.h"

/* localdecomp:start func_L39_00577308 */
typedef struct E_00577308 {
    u8 pad0[0x188];
    u8 f188;
    u8 f189;
    u8 pad1[0x558 - 0x18A];
    u8 f558;
    u8 pad2[0x5C0 - 0x559];
} E_00577308;
typedef struct R_00577308 {
    s32 v;
    u8 b;
} R_00577308;
__asm__(".extern D_L39_00225900, 16");
extern E_00577308 D_L39_00225900[8];
extern u8 D_001A5A3E[];
__asm__(".extern D_001D6C58_sda_00577308, 4");
extern s32 D_001D6C58_sda_00577308;
extern s32 func_L01_003F0398(R_00577308 *, E_00577308 *);

void func_L39_00577308(void)
{
    s32 i;
    s32 *q = &D_001D6C58_sda_00577308;
    for (i = 0; i < 8; i++) {
        E_00577308 *p = &D_L39_00225900[i];
        if (p->f558 != 0) {
            R_00577308 r;
            func_L01_003F0398(&r, p);
            if (D_001A5A3E[i] != 0) {
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
/* localdecomp:end func_L39_00577308 */
