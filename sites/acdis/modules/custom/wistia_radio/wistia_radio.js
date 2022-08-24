// wistia radio functions

jQuery(document).ready(function($){
	
	$("#edit-field-video-url input").change(function(){
		var field = $(this);
		var eurl = field.val();
		// console.log(eurl);
		// var video_id = eurl.replace(/\/$/, '').match(/.*\/(.*?)$/)[1];
		// console.log(video_id);
		if (eurl != ''){
			$(".video_url_message").remove();
			field.after('<span class="video_url_message" style="padding-left:10px;">Retrieving MP4 URL...</span>');
			
			$.ajax({
				dataType: "json",
				url: 'https://fast.wistia.net/oembed',
				data: 'url='+ encodeURIComponent(eurl) +'&format=json',
				success: function(data){
					if (data.thumbnail_url){
						$(".video_url_message").remove();
						var asset_id = data.thumbnail_url.match(/.*\/(.*?)(\.jpg.*)$/)[1];
						// console.log(asset_id);
						var mp4_url = 'https://embed-ssl.wistia.com/deliveries/'+ asset_id +'/file.mp4';
						$("#edit-field-mp4-url input").val(mp4_url);
					}
					else {
						$(".video_url_message").text('There was a problem... check the Video URL and try again (1)');
					}
				},
				error: function() {
					$(".video_url_message").text('There was a problem... check the Video URL and try again (2)');
				}
			});
		}
	});
	
})