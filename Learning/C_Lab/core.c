#include <stdio.h>

struct SmartLock {
    int lock_id;
    char is_locked;  // 'Y' (or) 'N'
};

void unlock(struct SmartLock* smartlock_ptr) {
    smartlock_ptr->is_locked = 'N';
}

int main() {
    struct SmartLock sl;
    sl.lock_id = 101;
    sl.is_locked = 'Y';

    printf("Lock ID:  %d.\n", sl.lock_id);
    printf("Lock Status before function call:  %c\n", sl.is_locked);

    printf("Unlocking SmartLock.\n");
    unlock(&sl);
    
    printf("Lock Status after function call:  %c\n", sl.is_locked);
}
