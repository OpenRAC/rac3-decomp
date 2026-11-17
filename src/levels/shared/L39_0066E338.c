#include "common.h"

/* declared by functions of L39_0066DF40.c, which this file was cut from */
typedef struct Node0066B638 {
    u8 pad[32];
    struct Node0066B638 *prev;
    struct Node0066B638 *next;
} Node0066B638;
extern Node0066B638 *D_L39_0024CF7C;

/* localdecomp:start func_L39_0066E338 */
extern Node0066B638 *D_L39_0024CF7C;
typedef struct S_0066BA18 { u8 pad[36]; struct S_0066BA18 *next; u8 pad2[48]; s32 id; } S_0066BA18;

S_0066BA18 *func_L39_0066E338(s32 id) {
    S_0066BA18 *p = ((S_0066BA18 * *)&D_L39_0024CF7C)[0];
    while (p != 0) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
/* localdecomp:end func_L39_0066E338 */
