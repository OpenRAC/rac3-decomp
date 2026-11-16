/* PAL near miss (Codex wave 6): near miss: 10 words differ with the file's flags.
 * Worker's note: 10 diff in tail register allocation: result a2 versus v0, address v1 versus a0 and byte v0 versus v1; baseline/else-zero/parameter-result identical; best build/codex/w292/func_L01_003290D0.base.log. Fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_L01_003290D0 */
extern s32 D_001D545C;
extern E_00329038 D_L01_002AEA10[];
extern u8 D_001426E0[];
extern u8 D_001BBC40[];
extern u8 D_L01_001DFE80[];
s32 func_L01_003290D0(s32 arg) {
    L_00329038 *v = *(L_00329038 **)((u8 *)arg + 0x68);
    s32 i, result;
    u8 b;
    E_00329038 *e;
    if (v->b53 != 255) {
        b = v->b53;
        e = (E_00329038 *)((u8 *)D_L01_002AEA10 + b * 56);
        if (e->w12 != 0 && D_001426E0[e->w12] == 1) return 1;
    }
    i = v->w8;
    if (i != -1) {
        result = 0;
        if (D_001BBC40[i + D_001D545C * 16] & 128) {
            result = 1;
            if (!(D_L01_001DFE80[i] & 128)) goto done;
        } else goto done;
    }
    result = 0;
done:
    return result;
}
/* localdecomp:end func_L01_003290D0 */
