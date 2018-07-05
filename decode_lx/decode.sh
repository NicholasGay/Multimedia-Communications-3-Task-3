#!/bin/sh

./ffmpeg -i video.mp4 -c:v rawvideo -pix_fmt yuv420p video_dec.yuv
./ffmpeg -s:v 640x360 -r 24 -i video_dec.yuv -s:v 640x360 -r 24 -i video_ref.yuv -filter_complex "[0:v]setpts=PTS-STARTPTS[a]; [1:v]setpts=PTS-STARTPTS[b]; [a][b]psnr="stats_file=video_stats.log"[out]" -map "[out]" -f rawvideo -y /dev/null
