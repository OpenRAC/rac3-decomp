/* functional: high. 4 words differ at level_01 (slot byte reloaded instead of kept in a register); same reads, writes and returns. Uses a draft whose address table D_L01_001EEC80 is the 64-byte-entry effect ring (see func_L01_00446A70); declared here as s8[] which conflicts with other files declaring it in the same TU. */

extern s8 D_L01_001EEC80[];

/* Finds the effect slot owned by this object. Returns it if it matches the flag mask, otherwise releases the slot when allowed. */

void *func_L01_00447490(void *object, u32 flag_mask, s32 keep_slot) {
    s8 *entry;
    void *owner;

    if (*(u8 *)((s8 *)object + 0xA8) == 0xFF) {
        return 0;
    }
    entry = (s8 *)&D_L01_001EEC80 + (*(u8 *)((s8 *)object + 0xA8) << 6);
    owner = *(void **)(entry + 0x38);
    if (owner != object) {
        return 0;
    }
    if (*(u32 *)(entry + 0x24) & flag_mask) {
        return entry;
    }
    if (keep_slot == 0) {
        *(u8 *)((s8 *)owner + 0xA8) = 0xFF;
    }
    return 0;
}
