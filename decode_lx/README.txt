The content of this fodler should be copied to folder where the video segments have been downloaded.

1. Untar the static ffmpeg build (ffmpeg.static.32bit* for 32 bit or ffmpeg.static.64bit* variants of linux)
	tar -xvf ffmpeg.static.64bit.2014-03-02.tar.gz
2. change the user privileges for concat_lx.sh
	chmod a+x concat_lx.sh
3. Run concat_lx.sh
	./concat_lx.sh
		- generates video.mp4
5. Download the zip file for video_ref.yuv from GigaMove (the link is on Moodle) and unzip it in this folder
4. Run decode.sh
	./decode.sh
		- this generates two files: video_dec.yuv (raw file for the downloaded video) and video_stats.log (log with statistics for each frame)
		- please also write the avg value of the psnr from the output in your report
