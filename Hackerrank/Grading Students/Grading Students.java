public static List<Integer> gradingStudents(List<Integer> grades) {
 for(int i=0;i<grades.size();i++){ //iterate through the array
      if(grades.get(i)>=38){ //check whether to round or not

        //rounding the marks
         int r=grades.get(i)%5;
         int diff=Math.abs(r-5);
         if(diff<3)
           grades.set(i,grades.get(i)+diff);
     }
 }
 return grades;

}