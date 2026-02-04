var audioTag = document.getElementById("myAudio");
var timRange = document.getElementById("timeRange");
var volRange = document.getElementById("volumeRange");

const audio = document.getElementById("myAudio");
const rows = document.querySelectorAll(".other_musics tr");

//default volume
audioTag.volume = volRange.value;

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

//volumeRang
// Change volume when slider moves
volRange.addEventListener("input", () => {
    audio.volume = volRange.value;
});

//change the music:
rows.forEach(row => {
            row.addEventListener("click", () => {
                audio.src = row.getAttribute("data-audio");
                document.getElementById("songImage").src = row.getAttribute("data-img");
            });
        });



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