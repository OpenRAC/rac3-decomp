/* functional: high. Finds the next selectable entry of a list object: starting after index start (or after the current selection at +0x290 when start is -1), cycles through the count at +0x10C entries (table at +0x110) and returns the first index whose entry state (+4) is >= 3, or -1 if none. */
typedef struct { u8 pad0[4]; s32 f4; } E_0068B1E0;
typedef struct { u8 pad0[0x10C]; s32 count; E_0068B1E0 *items[1]; } L_0068B1E0;

s32 func_L39_0068B1E0(L_0068B1E0 *self, s32 start) {
    s32 found = -1;
    s32 n;
    s32 i;
    s32 idx;

    if (start == -1) {
        start = *(s32 *)((u8 *)self + 0x290);
    }
    n = self->count;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            idx = (start + 1 + i) % n;
            if (self->items[idx]->f4 >= 3) {
                found = idx;
                break;
            }
        }
    }
    return found;
}
