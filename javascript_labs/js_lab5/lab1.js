class Clock{
    #intervalid;
    constructor(time){
        this.hours = Number(time.slice(0,2));
        this.minutes = Number(time.slice(3,5));
        this.seconds = Number(time.slice(6,8));
    }

    static formatTime(hours, minutes, seconds){
        hours = String(hours).padStart(2, '0');
        minutes = String(minutes).padStart(2, '0');
        seconds = String(seconds).padStart(2, '0');


        const time_string = `${hours}:${minutes}:${seconds}`;
        return time_string;
    }

    #tick(){
        this.seconds++;
        if(this.seconds === 60){
            this.seconds = 0;
            this.minutes++;
        }
        if(this.minutes === 60){
            this.minutes = 0;
            this.hours++;
        }
        if(this.hours === 24){
            this.hours = 0;
        }
        console.log(Clock.formatTime(this.hours, this.minutes, this.seconds));

        //if (this.#alarmTime) this.#checkAlarm();
    }
    /*get tick(){
        return this.#tick;
    }*/

    start(){
        this.#intervalid = setInterval(() => this.#tick(), 1000);
        console.log(this.getTime());
    }
    
    stop(){
        clearInterval(this.#intervalid);
    }
    getTime(){
        return Clock.formatTime(this.hours, this.minutes, this.seconds);
    }
}

class AlarmClock extends Clock{
    #alarmTime;
    #intervalID
    constructor(time, alarmTime){
        super(time);
        this.#alarmTime = alarmTime;
        }
    #checkAlarm(){
        let currentTime = this.getTime();        
        return currentTime === this.#alarmTime;
    }


    start(){ 
        
        //overrride
        super.start();
        this.#intervalID = setInterval(() => {
            if(this.#checkAlarm()){
                console.log("Wake up! it's time!");
                this.stop();
            }
        }, 1000);
    }
    stop(){
        clearInterval(this.#intervalID);
        super.stop();
    }

    setAlarm(newAlarmTime){
        this.#alarmTime = Clock.formatTime(newAlarmTime);
    }

}

const myClock = new Clock("23:59:55");
const AlarmClock_1 = new AlarmClock("07:59:55", "08:00:00");

console.log(`my clock: ${myClock.getTime()}`);
console.log(`alarm clock: ${AlarmClock_1.getTime()}`);

console.log("++++++++++++++ lets count +++++++++++++++");

AlarmClock_1.start();

