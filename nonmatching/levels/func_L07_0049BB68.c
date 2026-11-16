/* PAL near miss (Codex wave 7): near miss: 28 words differ with the file's flags.
 * Worker's note: 28 instruction differences; build/codex/w369/L07-02.log. In-place outer increment remains PRE temporary (s3), swaps inner boolean s2/s3 and adds final move; three loop/goto forms produce identical 612-byte text SHA prefix a700c2e8f708ffb6. Retail switch ...
 */
#include "common.h"
/* localdecomp:start func_L07_0049BB68 */
typedef struct Entry_0049BB68 {
    s32 tag; u32 unused4, unused8;
    union { u32 id; u32 *list; } condition;
    u32 kind; u8 active; u8 pad15[3];
} Entry_0049BB68;
extern Entry_0049BB68 D_L07_002EE2B8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
void func_L07_0049BB68(void) {
    extern s32 func_L01_0041A4F0(void);
    s32 i, j;
    i = 0;
    while (D_L07_002EE2B8[i].tag) {
        switch (D_L07_002EE2B8[i].kind) {
        case 0:
            D_L07_002EE2B8[i].active = (D_00142BA0[D_L07_002EE2B8[i].condition.id >> 2] & (1 << (D_L07_002EE2B8[i].condition.id & 31))) != 0 || func_L01_0041A4F0();
            break;
        case 1:
            D_L07_002EE2B8[i].active = 0;
            for (j = 0; D_L07_002EE2B8[i].condition.list[j]; j++) {
                D_L07_002EE2B8[i].active = D_L07_002EE2B8[i].active ||
                    (D_00142BA0[D_L07_002EE2B8[i].condition.list[j] >> 2] & (1 << (D_L07_002EE2B8[i].condition.list[j] & 31))) != 0 || func_L01_0041A4F0();
            }
            break;
        case 2:
            D_L07_002EE2B8[i].active = (D_00142BA0[D_L07_002EE2B8[i].condition.id >> 2] & (1 << (D_L07_002EE2B8[i].condition.id & 31))) != 0 || func_L01_0041A4F0();
            break;
        case 3:
        case 4:
        default:
            D_L07_002EE2B8[i].active = D_00142693[0] || func_L01_0041A4F0();
            break;
        }
        i++;
    }
}
/* localdecomp:end func_L07_0049BB68 */
