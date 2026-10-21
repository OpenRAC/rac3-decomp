/* Near miss of func_003CE250 with its file's own flags: tools/check.py reports 23 diff
   (the version it replaces: 27).
*/

/* func_003CE250.
   Retail reaches these globals with %hi/%lo (lui + lw/sw), not through $gp.
   A sized scalar declaration puts a global in small data and the compiler
   then uses $gp-relative accesses, so the globals are declared as structs
   bigger than the -G8 threshold (hence not small data) and their first
   member (the value retail reads/writes) is used directly.
   The alias names are the ones the linker script defines for these addresses. */

/* localdecomp:start func_003CE250 */
typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;

/* a global bigger than the small data threshold is reached with %hi/%lo */
typedef struct { int v; int pad[4]; } G16;
typedef struct { void *v; int pad[4]; } G16P;

extern G16 D_001DA050_003CE2C0;
extern G16P D_001DA5F0;
extern G16 D_001DA600_003CE2C0;
extern G16 D_001D4BB4_003CE2C0;
extern G16 D_001D4BB0_003CE2C0;
extern int D_001D9BFC;

void func_003CE250(void) {
    int old;
    int saved;
    int count;
    int index;
    Config_003C8CE0 *config;

    old = D_001DA050_003CE2C0.v;
    index = 0;
    config = (Config_003C8CE0 *)D_001DA5F0.v;
    D_001DA600_003CE2C0.v = old;
    saved = D_001D4BB4_003CE2C0.v;
    old += 0x10;
    count = config->count;
    D_001DA050_003CE2C0.v = old;
    D_001D4BB0_003CE2C0.v = saved;
    D_001D9BFC = 0;
    if (count > 0) {
        do {
            old = (int)config->buffer;
            saved = index * 0x10;
            index++;
            saved += old;
            *(unsigned long *)saved = 0;
            old = config->count;
        } while (index < old);
    }
}
/* localdecomp:end func_003CE250 */
