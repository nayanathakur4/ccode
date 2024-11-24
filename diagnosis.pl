% Facts: Define symptoms and associated conditions
symptom(fever).
symptom(cough).
symptom(headache).
symptom(sore_throat).
symptom(fatigue).
symptom(rash).
symptom(nausea).
symptom(vomiting).
symptom(diarrhea).

% Conditions based on combinations of symptoms
condition(flu) :- symptom(fever), symptom(cough), symptom(fatigue).
condition(cold) :- symptom(cough), symptom(sore_throat), symptom(headache).
condition(allergy) :- symptom(sneeze), symptom(rash).
condition(gastroenteritis) :- symptom(nausea), symptom(vomiting), symptom(diarrhea).
condition(covid19) :- symptom(fever), symptom(cough), symptom(fatigue), symptom(sore_throat).

% Rule to diagnose condition based on provided symptoms
diagnose(Condition) :- condition(Condition).

% Rule to find symptoms of a specific condition
symptoms_of(Condition, Symptoms) :-
    findall(S, (condition(Condition), symptom(S)), SymptomsList),
    list_to_set(SymptomsList, Symptoms).
