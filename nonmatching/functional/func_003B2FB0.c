/* functional: high. Queue/pool init: stores stream, entries, capacity, clears count and write index, then for each of `capacity` entries (stride 0x27E40 bytes) clears the first word and writes its index at +4. Verified against PAL asm; the draft's `volatile` on the queue pointer is dropped (not hardware memory). */
typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003B2FB0;
void func_003B2FB0(Queue_003B2FB0 *queue, s32 stream, u8 *entries, s32 capacity) {
    s32 index = 0;
    s32 offset;
    queue->count = 0;
    queue->stream = stream;
    queue->entries = entries;
    queue->capacity = capacity;
    queue->write_index = 0;
    if (capacity > 0) {
        offset = 0;
        do {
            *(s32 *)(offset + (s32)queue->entries) = 0;
            *(s32 *)(offset + (s32)queue->entries + 4) = index;
            index++;
            offset += 0x27E40;
        } while (index < capacity);
    }
}
