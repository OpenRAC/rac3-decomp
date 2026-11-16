#include "common.h"

/* localdecomp:start func_L39_00669B68 */
typedef struct {
    s32 value0;
} Entry_L39_00669B68;

extern Entry_L39_00669B68 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, Entry_L39_00669B68 *);
extern s32 D_001A5F78[];

/* Allocates an entry with func_L39_006699B0 and, if it succeeds, stores in it the result of
 * func_L39_00669978 called with 2, the object and the global D_001A5F78[0]. */
void func_L39_00669B68(void *object) {
    Entry_L39_00669B68 *entry = func_L39_006699B0();
    if (entry != 0) {
        entry->value0 = func_L39_00669978(2, object, D_001A5F78[0], object, entry);
    }
}
/* localdecomp:end func_L39_00669B68 */
