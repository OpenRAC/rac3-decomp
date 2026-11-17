#include "common.h"

/* localdecomp:start func_L01_0045E420 */
typedef struct {
    u8 data[36];
} Ent45B118;

extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern u8 D_L01_001FD900[];
extern u8 D_L01_001FFDD0[];
extern Ent45B118 D_L01_002F7334[];

Ent45B118 *func_L01_0045E420(s32 id) {
    u8 idx = D_L01_001FDBD0[id];
    if (idx == 255) {
        return 0;
    }
    if (D_L01_001FD9F0[idx] != id) {
        return &D_L01_002F7334[D_L01_001FFDD0[idx]];
    }
    return &D_L01_002F7334[D_L01_001FD900[idx]];
}
/* localdecomp:end func_L01_0045E420 */

/* localdecomp:start func_L01_0045E4B0 */
typedef struct M_45E4B0 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x28 - 0x21];
    struct M_45E4B0 *next;
    u8 pad2C[0x34 - 0x2C];
    u16 h34;
    u8 pad36[0x64 - 0x36];
    void (*w64)(struct M_45E4B0 *);
    u8 pad68[0x100 - 0x68];
} M_45E4B0;
extern M_45E4B0 *D_L01_001E001C;
extern M_45E4B0 *D_L01_001E0028;
extern M_45E4B0 *D_L01_0021E860[];
extern void func_003C6FE0(M_45E4B0 *);
extern void func_003C7C38(M_45E4B0 *);
void func_L01_0045E4B0(void) {
    M_45E4B0 *m;
    M_45E4B0 *prev;
    M_45E4B0 *n;

    D_L01_0021E860[0] = 0;
    D_L01_001E0028 = 0;
    prev = 0;
    for (n = D_L01_001E001C; n->b20 != 255; n++) {
        if ((n->b20 & 0x80) || (n->h34 & 2)) {
            continue;
        }
        if (prev != 0) {
            prev->next = n;
        } else {
            D_L01_001E0028 = n;
        }
        prev = n;
    }
    if (prev != 0) {
        prev->next = 0;
    }
    for (m = D_L01_001E0028; m != 0; m = m->next) {
        if (*(s8 *)&m->b20 < 0) {
            continue;
        }
        if (!(m->h34 & 0x40)) {
            func_003C6FE0(m);
        }
        if (m->w64 != 0 && !(m->h34 & 2)) {
            m->w64(m);
        }
        if (!(m->h34 & 4)) {
            func_003C7C38(m);
        }
    }
}
/* localdecomp:end func_L01_0045E4B0 */
