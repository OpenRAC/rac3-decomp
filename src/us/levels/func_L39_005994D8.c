#include "common.h"

/* localdecomp:start func_L39_005994D8 */
typedef struct {
    s32 f00;
    s32 f04;
    u8 pad08[0x20 - 0x08];
    s32 f20;
    s32 f24;
} S_00498AA0;

typedef struct {
    u8 pad00[8];
    s32 f08;
    u8 pad0C[4];
} Ent_005994D8;

typedef struct {
    u8 pad00[0x70];
    s16 h70;
    u8 pad72[4];
    u16 h76;
    u8 pad78[0x98 - 0x78];
    s16 h98;
    u8 pad9A[4];
    u16 h9E;
} S_002257E0;

extern S_00498AA0 D_L39_00498AA0;
extern S_002257E0 D_L39_002257E0;
typedef struct {
    u8 pad00[0x2648];
    s32 w2648[1];
} S_001F0B80;
extern S_001F0B80 D_L39_001F0B80;
__asm__(".extern D_L39_001F0B80, 16");
__asm__(".extern D_001E0530_sda, 4");
extern Ent_005994D8 *D_001E0530_sda;

void func_L39_005994D8(void) {
    s32 a;
    s32 i;
    Ent_005994D8 *tbl;
    Ent_005994D8 *e;

    if (D_L39_00498AA0.f00 != 0) {
        i = D_L39_00498AA0.f20;
        tbl = D_001E0530_sda;
        if (i != -1) {
            e = (Ent_005994D8 *)(i * 16 + (s32)tbl);
            a = e->f08;
            if (a != -1 && D_L39_001F0B80.w2648[a] != 0) {
                if (a == D_L39_002257E0.h98 - 0x1B58 || a == D_L39_002257E0.h70 - 0x1B58) {
                    if ((u16)(D_L39_002257E0.h76 - 6) >= 2) {
                        D_L39_002257E0.h76 = 5;
                    }
                    if ((u16)(D_L39_002257E0.h9E - 6) >= 2) {
                        D_L39_002257E0.h9E = 5;
                    }
                }
            }
        }
        D_L39_00498AA0.f00 = 0;
        D_L39_00498AA0.f24 = -1;
        D_L39_00498AA0.f20 = -1;
        D_L39_00498AA0.f04 = 0;
    }
}
/* localdecomp:end func_L39_005994D8 */
