#include "common.h"

/* localdecomp:start func_L39_00669C50 */
typedef struct {
    u8 reserved0[8];
    s32 field8;
    u8 reservedC[0x11C];
    s32 field128;
} State_L39_00669C50;

extern State_L39_00669C50 D_001A5E50;
extern void *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, s32, void *);

/* Fetches a free entry from func_L39_006699B0 and, if there is one, fills its first word with the
 * result of func_L39_00669978(6, object, ...) using two fields of the global D_001A5E50. */
void func_L39_00669C50(void *object) {
    void *entry = func_L39_006699B0();
    if (entry != 0) {
        *(s32 *)entry = func_L39_00669978(6, object, D_001A5E50.field128,
                                          D_001A5E50.field8, entry);
    }
}
/* localdecomp:end func_L39_00669C50 */
