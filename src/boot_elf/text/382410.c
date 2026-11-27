#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void *D_001D99A0;
extern s32 func_003823D0(s32);
extern s32 func_00382360(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00382410 */
__asm__(".extern D_001D99A0, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382410(fallback)
s32 fallback;
{
    s32 index = func_00382360(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D99A0 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382410 */

/* localdecomp:start func_00382468 */
extern s32 func_00382410();
void func_00382468(void) {
    func_003823D0(func_00382410());
}
/* localdecomp:end func_00382468 */

/* localdecomp:start func_00382490 */
extern s32 D_001D5688;
void func_00382490(void) { D_001D5688 = 0; }
/* localdecomp:end func_00382490 */

/* US draft of func_00382498 (rac3-uya-decomp func_003824B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s32 D_001D5680;

/* localdecomp:start func_00382498 */
extern s32 D_001D5680;
void func_00382498(void) { D_001D5680 = 8; }
/* localdecomp:end func_00382498 */

/* localdecomp:start func_003824A8 */
extern void func_003980A0();
extern u8 D_001D5790[];
 
void func_003824A8(void) {
    func_003980A0(D_001D5790, 0, 0);
}
/* localdecomp:end func_003824A8 */
