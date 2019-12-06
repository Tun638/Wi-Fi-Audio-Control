const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>    
    <head>
        <meta content="text/html;charset=utf-8" http-equiv="Content-Type">
        <meta content="utf-8" http-equiv="encoding">
        <title>Wi-Fi Audio Control</title>
        <script src="https://ajax.aspnetcdn.com/ajax/jQuery/jquery-3.4.1.min.js"></script>

        <script>
    
            function changeBassGain(slider) {
                    
                var sync = $('#sync').is(":checked");

                if (sync) {
                    if (slider.id === 'left') {
                        $('#right').val($('#left').val());
                    } else if (slider.id === 'right') {
                        $('#left').val($('#right').val());
                    }
                }
    
                $.post("/bassGain", 
                    {
                        left: $('#left').val(),
                        right: $('#right').val()
                    },
                    function(data, status){
                        console.log("Data: " + data + "\nStatus: " + status);
                    }
                );               
            }    
    
        </script>

    </head>
<body>

    <form action="/bassgain" method="POST">
        <input type="range" name="left" id="left" min="0" max="33" value="30" onchange="changeBassGain(this);">
        <input type="checkbox" name="sync" id="sync" checked /> sync
        <input type="range" name="right" id="right" min="0" max="33" value="30" onchange="changeBassGain(this);">
    </form>   

</body>
</html> 
)=====";
