#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    volatile unsigned int latest_round_trip_time;
} NetworkData;

extern NetworkData g_network_data;

void set_latest_round_trip_time(unsigned int value);
unsigned int get_latest_round_trip_time(void);

#ifdef __cplusplus
}
#endif
