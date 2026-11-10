#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003C7C48);

/* localdecomp:start func_L03_003C7EF0 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_00142799[];

void func_L03_003C7EF0(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_00142799[0] != 0) {
        void *p = *(void **)((u8 *)arg0 + 0x24);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFBE);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | (*(u16 *)((u8 *)p + 0x44) & 0x1000));
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)p + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C7EF0 */

/* localdecomp:start func_L03_003C7F78 */
extern unsigned char D_0014279A[];

void func_L03_003C7F78(unsigned char *p) {
    if (p[0x20] == 0) {
        p[0x20] = 1;
    }
    if (D_0014279A[0] != 0) {
        unsigned char *q = *(unsigned char **)(p + 0x24);
        unsigned short f = *(unsigned short *)(p + 0x34) & 0xFFBE;
        *(unsigned short *)(p + 0x34) = f;
        *(unsigned short *)(p + 0x34) = f | (*(unsigned short *)(q + 0x44) & 0x1000);
        *(int *)(p + 0x98) = *(int *)(q + 0x10);
    } else {
        *(int *)(p + 0x98) = 0;
        *(unsigned short *)(p + 0x34) = ((*(unsigned short *)(p + 0x34) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) p, 1);
    }
}
/* localdecomp:end func_L03_003C7F78 */

/* localdecomp:start func_L03_003C8000 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279B[];

void func_L03_003C8000(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_0014279B[0] != 0) {
        void *o = *(void **)((u8 *)arg0 + 0x24);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFBE);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | (*(u16 *)((u8 *)o + 0x44) & 0x1000));
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)o + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C8000 */

/* localdecomp:start func_L03_003C8088 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279C[];

void func_L03_003C8088(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279C[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C8088 */

/* localdecomp:start func_L03_003C80E8 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279D[];

void func_L03_003C80E8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279D[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C80E8 */

/* localdecomp:start func_L03_003C8148 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279E[];

void func_L03_003C8148(void *arg0) {
    u8 *p;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_0014279E[0] != 0) {
        u16 f34 = *(u16 *)((u8 *)arg0 + 0x34);
        p = *(u8 **)((u8 *)arg0 + 0x24);
        f34 &= 0xFFBE;
        *(u16 *)((u8 *)arg0 + 0x34) = f34;
        f34 |= (*(u16 *)(p + 0x44)) & 0x1000;
        *(u16 *)((u8 *)arg0 + 0x34) = f34;
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)(p + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C8148 */
