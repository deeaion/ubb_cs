package org.producerConsumer.utils;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Generator {
    private static int NO_OF_COUNTRIES = 5;
    private static int NO_OF_PROBLEMS = 10;
    private static int MAX_NO_OF_PARTICIPANTS = 100;
    private static int MIN_NO_OF_PARTICIPANTS = 80;
    private static double PROBABILITY_OF_FAILURE_PER_COUNTRY = 10.0 / 100; // Convert to percentage
    private static double PROBABILITY_OF_FRAUD = 2.0 / 100; // Convert to percentage
    private static String OUTPUT_DIR = "src/main/resources/input_data";

    public static void generate() {

        // Create the output directory
        try {
            Files.createDirectories(Paths.get(OUTPUT_DIR));
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        Random random = new Random();
        // For each country
        for (int country = 0; country < NO_OF_COUNTRIES; country++) {
            int noOfParticipants = MIN_NO_OF_PARTICIPANTS + random.nextInt(MAX_NO_OF_PARTICIPANTS - MIN_NO_OF_PARTICIPANTS + 1);
            List<String> participants = new ArrayList<>();
            // Participant names: Pcountry_i
            for (int i = 0; i < noOfParticipants; i++) {
                participants.add("P" + country + "_" + i);
            }

            // Generate scores for each participant
            // Consider the probability of fraud
            Set<String> validScoreParticipants = new HashSet<>();

            for (int problem = 0; problem < NO_OF_PROBLEMS; problem++) {
                String filePath = OUTPUT_DIR + "/C" + country + "_" + "P" + problem + ".txt";
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
                    for (String participant : participants) {
                        int score;
                        if (validScoreParticipants.contains(participant) && random.nextDouble() < PROBABILITY_OF_FRAUD) {
                            score = -1; // Fraudulent score
                        } else if (random.nextDouble() < PROBABILITY_OF_FAILURE_PER_COUNTRY) {
                            score = 0; // Failed score
                        } else {
                            score = random.nextInt(101); // Valid score
                            validScoreParticipants.add(participant);
                        }
                        if (score != 0) { // Only write non-zero scores
                            writer.write(participant + " " + score);
                            writer.newLine();
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
