# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             src/main/cpp/agg_2.5/agg2d.cpp
             src/main/cpp/agg_2.5/src/agg_embedded_raster_fonts.cpp
             src/main/cpp/agg_2.5/src/agg_gsv_text.cpp
             src/main/cpp/agg_2.5/src/agg_curves.cpp
             src/main/cpp/agg_2.5/src/agg_bezier_arc.cpp
             src/main/cpp/agg_2.5/src/agg_sqrt_tables.cpp
             src/main/cpp/agg_2.5/src/agg_trans_double_path.cpp
             src/main/cpp/agg_2.5/src/agg_bspline.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_dash.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_smooth_poly1.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_stroke.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_bspline.cpp
             src/main/cpp/agg_2.5/src/agg_trans_single_path.cpp
             src/main/cpp/agg_2.5/src/agg_trans_affine.cpp
             src/main/cpp/agg_2.5/src/agg_rounded_rect.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_contour.cpp
             src/main/cpp/agg_2.5/src/agg_vpgen_clip_polygon.cpp
             #src/main/cpp/agg_2.5/src/agg_line_profile_aa.cpp
             src/main/cpp/agg_2.5/src/agg_arrowhead.cpp
             src/main/cpp/agg_2.5/src/agg_image_filters.cpp
             src/main/cpp/agg_2.5/src/agg_vcgen_markers_term.cpp
             src/main/cpp/agg_2.5/src/agg_arc.cpp
             src/main/cpp/agg_2.5/src/agg_line_aa_basics.cpp
             src/main/cpp/agg_2.5/src/agg_vpgen_clip_polyline.cpp
             src/main/cpp/agg_2.5/src/agg_trans_warp_magnifier.cpp
             src/main/cpp/agg_2.5/src/agg_vpgen_segmentator.cpp

             src/main/cpp/agg_2.5/font_freetype/agg_font_freetype.cpp
             )

include_directories(
                    src/main/cpp/agg_2.5
                    src/main/cpp/agg_2.5/include
                    src/main/cpp/agg_2.5/font_freetype
                    src/main/cpp/freetype2/include
                    src/main/cpp/freetype2/include/freetype
                   )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.


target_link_libraries( # Specifies the target library.
                   native-lib
                   freetype-lib
                   android
                   # Links the target library to the log library
                   # included in the NDK.
                   #${freetype-lib)
                   ${log-lib}
                   ${android-lib})

add_library(freetype-lib SHARED IMPORTED )
#set_target_properties(freetype-lib PROPERTIES IMPORTED_LOCATION "../freetype/build/intermediates/bundles/debug/jni/${ANDROID_ABI}/libfreetype-lib.so")
set_target_properties(freetype-lib PROPERTIES IMPORTED_LOCATION d://MyProjects/Research/Svg2Img/freetype/build/intermediates/bundles/debug/jni/${ANDROID_ABI}/libfreetype-lib.so)