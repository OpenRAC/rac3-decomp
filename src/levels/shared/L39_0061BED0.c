#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061BED0);

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

INCLUDE_ASM("asm/levels", func_L39_0061BFB0);

INCLUDE_ASM("asm/levels", func_L39_0061BFF8);

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

INCLUDE_ASM("asm/levels", func_L39_0061C1E0);

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

INCLUDE_ASM("asm/levels", func_L39_0061C2D0);

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
