#include "common.h"

/* NTSC-U version of func_00396568 (frontbin): 8 -> 10; 8 -> 10 */
#include "common.h"





typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_U_0032DB20_00396568[];
extern s32 D_U_001D9F0C_00396568;
extern void func_U_00391E78();
/* localdecomp:start func_U_00391D08 */
extern int D_U_001D9F0C_00396568 __attribute__((section(".sdata")));
extern void func_U_0038EC18(char *);
extern void func_U_00391E78(void);
int func_U_00391D08(int arg)
{
    char *rec;
    char *end;
    int count = 0;
    func_U_00391E78();
    rec = (char *)D_U_0032DB20_00396568;
    end = (char *)D_U_0032DB20_00396568 + 0x750;
    do {
        int v;
        if ((*(int *)(rec + 4) & 0x10) || D_U_001D9F0C_00396568) {
            v = *(int *)(rec + 0x7C);
            if (v < 10) {
                *(int *)(rec + 0x7C) = 10;
            }
            v = *(int *)(rec + 0x7C);
        } else {
            v = *(int *)(rec + 0x7C);
        }
        if (v > 0) {
            v = v - 1;
            *(int *)(rec + 0x7C) = v;
            if (v > 0) {
                count++;
                if (*(int *)(rec + 0x6C) < 30) {
                    *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) + 1;
                }
            } else if (*(int *)(rec + 0x6C) >= -5) {
                *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) - 1;
            }
        } else if (*(int *)(rec + 0x6C) >= -5) {
            *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) - 1;
        }
        if (*(int *)(rec + 0x68) != 0) {
            if (*(int *)(rec + 0x6C) == -6) {
                func_U_0038EC18(rec);
            }
        }
        if (arg != 0) {
            void (*handler)(char *) = *(void (**)(char *))(rec + 0x14);
            if (handler) {
                handler(rec);
            }
        }
        rec += 0x90;
    } while ((int)rec < (int)end);
    return count;
}
/* localdecomp:end func_U_00391D08 */
