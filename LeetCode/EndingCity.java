// assingment: find cities that have only 
// flying tickets in, not out from the city

/* Logic:
Divide cities to starting and end cities.
Delete all starting cities from ending cities. 
Name left will be the destination */

import java.util.ArrayList;
import java.util.List;

class EndingCity {

    public static void main(String[] args) {
        List<List<String>> paths = new ArrayList<>();

        List<String> path1 = new ArrayList<>();
        path1.add("London");
        path1.add("New York");
        paths.add(path1);

        List<String> path2 = new ArrayList<>();
        path2.add("New York");
        path2.add("Lima");
        paths.add(path2);

        List<String> path3 = new ArrayList<>();
        path3.add("Lima");
        path3.add("Sao Paulo");
        paths.add(path3);

        EndingCity solution = new EndingCity();
        String answer = solution.destCity(paths);
        System.out.println(answer);
    }

    public String destCity(List<List<String>> paths) {
        List<String> startingCities = new ArrayList<String>();
        List<String> endingCities = new ArrayList<String>();

        for (List<String> pairOfCities : paths) {
            startingCities.add(pairOfCities.get(0));
            endingCities.add(pairOfCities.get(1));
        }

        endingCities.removeAll(startingCities);

        return endingCities.get(0);
    }
}