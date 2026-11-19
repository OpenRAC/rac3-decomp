#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3963D0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

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
extern S_391D08 D_00331AE0_00396568[];
extern s32 D_001D9E8C_00396568;
extern void func_003966D8();
/* localdecomp:start func_00396568 */
extern int D_001D9E8C_00396568 __attribute__((section(".sdata")));
extern void func_00393450(char *);
extern void func_003966D8(void);
int func_00396568(int arg)
{
    char *rec;
    char *end;
    int count = 0;
    func_003966D8();
    rec = (char *)D_00331AE0_00396568;
    end = (char *)D_00331AE0_00396568 + 0x750;
    do {
        int v;
        if ((*(int *)(rec + 4) & 0x10) || D_001D9E8C_00396568) {
            v = *(int *)(rec + 0x7C);
            if (v < 8) {
                *(int *)(rec + 0x7C) = 8;
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
                func_00393450(rec);
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
/* localdecomp:end func_00396568 */
