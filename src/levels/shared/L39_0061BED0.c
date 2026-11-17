#include "common.h"

/* localdecomp:start func_L39_0061BED0 */
__asm__(".extern D_L39_0024CE20, 32");
extern void *D_L39_0024CE20[1];
typedef struct { u8 pad[0xE0]; s16 ids[8]; } S_0061BED0;
extern S_0061BED0 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");

void *func_L39_0061BED0(s32 id, s32 n) {
    s32 i;

    if (D_L39_00241640 == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->ids[i] == id) {
            if (n == 0) {
                return D_L39_0024CE20[i];
            }
            n--;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0061BED0 */

/* localdecomp:start func_L39_0061BF38 */
typedef struct {
    u8 pad0[0x4500];
} D_002FB100_t;
extern D_002FB100_t D_L39_002FB000[];

D_002FB100_t *func_L39_0061BF38(s32 i) {
    return &D_L39_002FB000[i];
}
/* localdecomp:end func_L39_0061BF38 */

/* localdecomp:start func_L39_0061BF50 */
__asm__(".extern D_L39_0024CE20, 32");
extern void *D_L39_0024CE20[1];
void *func_L39_0061BF50(s32 i) {
    return D_L39_0024CE20[i];
}
/* localdecomp:end func_L39_0061BF50 */

/* localdecomp:start func_L39_0061BF68 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern D_002FB100_t D_L39_002FB000[];

s32 func_L39_0061BF68(D_002FB100_t *a) {
    s32 i;

    for (i = 0; i < *D_L39_00241120; i++) {
        D_002FB100_t *p = &D_L39_002FB000[i];
        if (a == p) {
            return ((u8 *)p)[0x24C9];
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0061BF68 */

/* localdecomp:start func_L39_0061BFB0 */
__asm__(".extern D_L39_0024CE20, 32");
typedef struct { s32 w0; } E_0061BFB0;

u8 *func_L39_0061BFB0(u32 a) {
    s32 i;

    for (i = 0; i < 8; i++) {
        E_0061BFB0 *p = D_L39_0024CE20[i];
        if (p != 0 && p->w0 == a) {
            return (u8 *)p;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0061BFB0 */

/* localdecomp:start func_L39_0061BFF8 */
extern u8 D_001A5810[];
typedef struct { s32 f0; s32 f4; s32 f8; u8 pad[0x15C]; u8 b168; u8 b169; u8 pad2[2]; s32 f16C; } G_001A5CD0_0061BFF8;
extern G_001A5CD0_0061BFF8 D_001A5CD0[];
void func_L39_00620BE8(void);
void func_L39_0061D1B0(s32, s32);
void func_L39_00661A40(s32);
void func_L39_0066DEB0(void);
void func_L39_0061C2D0(void);
s32 func_L01_00436070(void *, void *, s32);
void func_L39_006729B0(void);
void func_L39_00674E08(void);
s32 func_L39_0054C780(s32, s32, s32, u8 *);
extern s32 (*D_L39_002405F0)(s32, s32, s32, u8 *);
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_002405F0, 16");
extern s32 *D_L39_00241120;

void func_L39_0061BFF8(void) {
    s32 i;
    s32 j;
    func_L39_00620BE8();
    func_L39_0061D1B0(D_001A5CD0->f8, D_001A5CD0->f16C);
    for (i = 0; i < *D_L39_00241120; i++) {
        func_L39_00661A40(i);
    }
    for (j = 7; j >= 0; j--) {
        D_001A5810[0xA4 + j] = 0;
    }
    func_L39_0066DEB0();
    func_L39_0061C2D0();
    func_L01_00436070(0, func_L39_00674E08, 0);
    D_001A5CD0->b169 = 0;
    func_L39_006729B0();
    D_L39_002405F0 = func_L39_0054C780;
}
/* localdecomp:end func_L39_0061BFF8 */

/* localdecomp:start func_L39_0061C0E0 */
extern D_002FB100_t *func_L39_0061BF38(s32 i);
extern void func_L01_0041A6E0(void);

void func_L39_0061C0E0(int a0, int a1) {
    ((char * (*)())func_L39_0061BF38)(a0)[9496] = a1;
    if (a1) {
        func_L01_0041A6E0();
    }
}
/* localdecomp:end func_L39_0061C0E0 */

/* localdecomp:start func_L39_0061C118 */
void func_00199868(void *);
void func_00199870(void *);
void func_L39_0051E200();
void func_L39_00528A88();
void func_L39_00556C10();
void func_L39_00557C80();
void func_L39_0061C1B0();
void func_L39_0061D150();
void func_L39_00662528();
void func_L39_00668BD8();
void func_L39_0066B700();
void func_L39_0066CDA0();
void func_L39_006774F0();
extern s8 D_001A58C6[];
extern s32 D_001D5A50_sda;
extern s8 D_001DA700_sda;
extern u8 D_L39_00666518[];
extern u8 D_L39_00666E48[];

void func_L39_0061C118(void) {
    D_001A58C6[0] = 0;
    D_001D5A50_sda = 5;
    func_00199868(D_L39_00666518);
    func_00199870(D_L39_00666E48);
    func_L39_006774F0();
    func_L39_0061C1B0();
    func_L39_0061D150();
    func_L39_00668BD8();
    func_L39_0066B700();
    D_001DA700_sda = 0;
    func_L39_00662528();
    func_L39_0066CDA0();
    func_L39_0051E200();
    func_L39_00528A88();
    func_L39_00556C10();
    func_L39_00557C80();
}
/* localdecomp:end func_L39_0061C118 */

/* localdecomp:start func_L39_0061C1B0 */
extern s32 D_L39_00264D68[];

/* from rac4-decomp's func_L00_006A9690, renamed */
void func_L39_0061C1B0(void) {
    s32 i;
    for (i = 0xFF; i >= 0; i--) {
        D_L39_00264D68[i] = 0;
    }
}
/* localdecomp:end func_L39_0061C1B0 */

/* localdecomp:start func_L39_0061C1E0 */
__asm__(".extern D_L39_0024BF60, 16");
extern u32 D_L39_0024BF60;
extern s32 D_L39_00264D68[];

void func_L39_0061C1E0(u32 a, s32 idx) {
    s32 i;

    if (D_L39_0024BF60 < a && idx == -1) {
        return;
    }
    if (idx == -1) {
        for (i = 0xFF; i >= 0; i--) {
            if (D_L39_00264D68[i] == 0 || D_L39_00264D68[i] == a) {
                D_L39_00264D68[i] = a;
                break;
            }
        }
    } else {
        D_L39_00264D68[idx] = a;
    }
}
/* localdecomp:end func_L39_0061C1E0 */

/* localdecomp:start func_L39_0061C258 */
extern s32 D_L39_00264D68[];

void func_L39_0061C258(s32 a0) {
    s32 i = 0;

    if (D_L39_00264D68[0] == a0) {
        D_L39_00264D68[0] = 0;
        return;
    }
loop:
    i++;
    if (i >= 0x100)
        return;
    if (D_L39_00264D68[i] != a0)
        goto loop;
    D_L39_00264D68[i] = 0;
}
/* localdecomp:end func_L39_0061C258 */

/* localdecomp:start func_L39_0061C2A8 */
/* from rac4-decomp's func_L41_005CDA90, renamed */
void func_L39_0061C2A8(void) {
    s32 var_v0;
    var_v0 = 255;
    do {
        var_v0 -= 1;
    } while (var_v0 >= 0);
}
/* localdecomp:end func_L39_0061C2A8 */

/* localdecomp:start func_L39_0061C2D0 */
typedef struct { u8 pad0[0xAA]; s16 fAA; u8 pad1[0x100 - 0xAC]; } E_0061C2D0;
__asm__(".extern D_L39_0024BF5C, 16");
__asm__(".extern D_L39_0024BF64, 16");
extern E_0061C2D0 *D_L39_0024BF5C;
extern E_0061C2D0 *D_L39_0024BF64;
extern E_0061C2D0 *D_L39_00264B68[32];
extern E_0061C2D0 *D_L39_00264BE8[32];
extern E_0061C2D0 *D_L39_00264C68[32];
extern E_0061C2D0 *D_L39_00264CE8[32];

void func_L39_0061C2D0(void) {
    s32 i;
    s32 j;
    E_0061C2D0 *p;
    for (j = 31; j >= 0; j--) {
        D_L39_00264B68[j] = 0;
    }
    for (j = 31; j >= 0; j--) {
        D_L39_00264BE8[j] = 0;
    }
    for (j = 31; j >= 0; j--) {
        D_L39_00264C68[j] = 0;
    }
    for (j = 31; j >= 0; j--) {
        D_L39_00264CE8[j] = 0;
    }
    for (p = D_L39_0024BF5C; p < D_L39_0024BF64; p++) {
        if (p->fAA == 0x19C4) {
            for (i = 0; i < 32; i++) {
                if (D_L39_00264B68[i] == 0) {
                    D_L39_00264B68[i] = p;
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0061C2D0 */

/* localdecomp:start func_L39_0061C400 */
typedef struct {
    u8 pad00[0x56C];
    s32 f56C;
    s32 f570;
    u8 pad01[0x5C0 - 0x574];
} Entry;
extern Entry D_00225780[];
extern void func_L39_006775B8(void);

/* from rac4-decomp's func_L00_006A98C0, renamed */
void func_L39_0061C400(void) {
    Entry *p;
    s32 end;
    func_00199868(0);
    func_00199870(0);
    func_L39_006775B8();
    p = D_00225780;
    end = (s32)p + 0x2E00;
    do {
        p->f56C = 0;
        p->f570 = 0;
        p++;
    } while ((s32)p < end);
}
/* localdecomp:end func_L39_0061C400 */
