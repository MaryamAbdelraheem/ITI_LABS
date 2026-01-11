var audioTag = document.getElementById("myAudio");
var timRange = document.getElementById("timeRange");

console.log(audioTag);
console.log(timRange);


// when audio metadata is loaded --> give audio duration =  time range
audioTag.addEventListener("loadedmetadata", function () {
    //set max value of range = audio duration (seconds)
    timRange.max = audioTag.duration
})


//update range value while audio is playing
audioTag.addEventListener("timeupdate", function () {
    timRange.value = audioTag.currentTime;
})


timRange.addEventListener("input", function () {
    audioTag.currentTime = timRange.value;
})



function playAudio() {
    audioTag.play()
}
function pauseAudio() {
    audioTag.pause()
}

function stopAudio() {
    audioTag.pause();
    audioTag.currentTime = 0;
}