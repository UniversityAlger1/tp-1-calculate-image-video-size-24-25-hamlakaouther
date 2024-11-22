#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {

   // Bits per pixel for colored image (8+8+8=24 bits)
   float bitsPerPixel = 24;

   // Calculate the total number of pixels
   float totalPixels = w * h;

   // Calculate the total size in bits
   float totalBits = totalPixels * bitsPerPixel;
   float size;

   // Conversion factors
   float BITS_TO_BYTES = 8.0; // 1 byte = 8 bits
   float BITS_TO_KILOBITS = 1024.0; //1 KB = 1024 bytes
   float KILOBITS_TO_MEGABITS = 1024.0;   //1 MB = 1024 KB
   float MEGABITS_TO_GIGABITS = 1024.0;   //1 GB = 1024 MB
   
   // Convert based on the unit provided
    if (strcmp(unit, "bt") == 0) {

        // Return size in bits
        return (float)totalBits;

    } else if (strcmp(unit, "b") == 0) {

        // Convert bits to bytes
        return totalBits / BITS_TO_BYTES;

    } else if (strcmp(unit, "kb") == 0) {

        // Convert bits to kilobytes
        return totalBits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES);

    } else if (strcmp(unit, "mb") == 0) {

        // Convert bits to megabytes
        return totalBits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES * KILOBYTES_TO_MEGABYTES);

    } else if (strcmp(unit, "gb") == 0) {

        // Convert bits to gigabytes
        return totalBits / (BITS_TO_BYTES * BYTES_TO_KILOBYTES * KILOBYTES_TO_MEGABYTES * MEGABYTES_TO_GIGABYTES);
        
    } else {
        // Invalid unit, return 0
        return 0.0f;
    }
}