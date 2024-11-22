#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {

   // Calculate the size of one color frame (24 bits per pixel)
    long size_per_frame_color = w * h * 24;  // In bits

    // Calculate the size of one black-and-white frame (8 bits per pixel)
    long size_per_frame_bw = w * h * 8;  // In bits

    // Calculate the total number of frames for each section
    long total_frames_color = durationMovie * fps;
    long total_frames_bw = durationCredits * fps;

    // Total size of the video in bits
    long total_bits = (size_per_frame_color * total_frames_color) + (size_per_frame_bw * total_frames_bw);

    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {

        // Return size in bits
        return (float)total_bits;

    } else if (strcmp(unit, "b") == 0) {

        // Convert bits to bytes (1 byte = 8 bits)
        return total_bits / BITS_TO_BYTES;

    } else if (strcmp(unit, "kb") == 0) {

        // Convert bits to kilobytes (1 KB = 1024 bytes)
        return total_bits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES);

    } else if (strcmp(unit, "mb") == 0) {

        // Convert bits to megabytes (1 MB = 1024 KB)
        return total_bits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES * KILOBYTES_TO_MEGABYTES);

    } else if (strcmp(unit, "gb") == 0) {

        // Convert bits to gigabytes (1 GB = 1024 MB)
        return total_bits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES * KILOBYTES_TO_MEGABYTES * MEGABYTES_TO_GIGABYTES);
        
    } else {
        // Invalid unit, return 0
        return 0.0f;
    }
}