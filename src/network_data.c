#include "network_data.h"

#ifdef __cplusplus
#include <atomic>
#define ATOMIC_LOAD(var) std::atomic_load_explicit(&(var), std::memory_order_relaxed)
#define ATOMIC_STORE(var, value) std::atomic_store_explicit(&(var), (value), std::memory_order_relaxed)
#else
#define ATOMIC_LOAD(var) __atomic_load_n(&(var), __ATOMIC_RELAXED)
#define ATOMIC_STORE(var, value) __atomic_store_n(&(var), (value), __ATOMIC_RELAXED)
#endif

NetworkData g_network_data;

void set_latest_round_trip_time(unsigned int value) {
    ATOMIC_STORE(g_network_data.latest_round_trip_time, value);
}

unsigned int get_latest_round_trip_time(void) {
    return ATOMIC_LOAD(g_network_data.latest_round_trip_time);
}
