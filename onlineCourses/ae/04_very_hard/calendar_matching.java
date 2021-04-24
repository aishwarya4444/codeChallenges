import java.util.*;

class Time {
  int start;
  int end;
  Time(int start, int end) {
    this.start = start;
    this.end = end;
  }
}

class Program {
  public static List<StringMeeting> calendarMatching(
      List<StringMeeting> calendar1,
      StringMeeting dailyBounds1,
      List<StringMeeting> calendar2,
      StringMeeting dailyBounds2,
      int meetingDuration) {
    // Write your code here.
    List<Time> cal1 = getTime(calendar1, dailyBounds1);
    List<Time> cal2 = getTime(calendar2, dailyBounds2);

    Queue<Time> minHeap = concatCal(cal1, cal2);
    List<Time> merged = new ArrayList<>();
    List<StringMeeting> free = new ArrayList<>();

    while(minHeap.size() > 0) {
      Time time = minHeap.poll();
      if(minHeap.size()>0 && time.end>=minHeap.peek().start) {
        time.end = Math.max(time.end, minHeap.peek().end);
        minHeap.poll();
        minHeap.add(time);
      } else {
        merged.add(time);
      }
    }

    for(int n=1; n<merged.size(); n++) {
      int startMins = merged.get(n-1).end;
      int endMins = merged.get(n).start;
      if(endMins-startMins < meetingDuration) {
        continue;
      }
      String start = minsToString(startMins);
      String end = minsToString(endMins);
      free.add(new StringMeeting(start, end));
    }

    return free;
  }

  private static List<Time> getTime(List<StringMeeting> cal, StringMeeting bound) {
    StringMeeting previous = new StringMeeting("0:00", bound.start);
    StringMeeting latter = new StringMeeting(bound.end, "24:00");
    List<Time> newCal = new ArrayList<>();
    int start, end;

    cal.add(previous);
    cal.add(latter);

    for(StringMeeting meeting: cal) {
      start = stringToMins(meeting.start);
      end = stringToMins(meeting.end);
      newCal.add(new Time(start, end));
    }

    return newCal;
  }

  private static int stringToMins(String time) {
    int colonIdx = time.indexOf(":");
    int hours = Integer.parseInt(time.substring(0, colonIdx));
    int mins = Integer.parseInt(time.substring(colonIdx+1, time.length()));
    return hours*60 + mins;
  }

  private static String minsToString(int mins) {
    int hr=mins/60;
    mins %= 60;
    if(mins<10) {
      return Integer.toString(hr) + ":0" + Integer.toString(mins);
    } else {
      return Integer.toString(hr) + ":" + Integer.toString(mins);
    }
  }

  private static Queue<Time> concatCal(List<Time> cal1, List<Time> cal2) {
    Queue<Time> minHeap = new PriorityQueue<>((t1, t2) -> {
      return t1.start - t2.start;
    });

    for(Time time: cal1) {
      minHeap.add(time);
    }

    for(Time time: cal2) {
      minHeap.add(time);
    }

    return minHeap;
  }

  static class StringMeeting {
    public String start;
    public String end;

    public StringMeeting(String start, String end) {
      this.start = start;
      this.end = end;
    }
  }
}
