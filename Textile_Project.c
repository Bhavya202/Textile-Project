#include <stdio.h>
#include <string.h>

/* Latest results used in the final report */
float reportTex = -1, reportDenier = -1, reportNm = -1;
float reportGSM = -1, reportProduction = -1;
float reportCostPerMetre = -1, reportProfit = -1, reportSellingPrice = -1;
int reportTotalDefects = -1;
float reportDefectPercent = -1;
char reportQuality[20] = "Not calculated";
char reportCommonDefect[30] = "Not calculated";

/* Simple inventory arrays */
#define MAX_ITEMS 50
char itemName[MAX_ITEMS][50];
char itemCategory[MAX_ITEMS][20];
float itemStock[MAX_ITEMS], itemReorder[MAX_ITEMS];
int itemCount = 0;

void yarnCount()
{
    int choice;
    float wt, l;

    printf("\n+==================================================+");
    printf("\n|              YARN COUNT CALCULATOR               |");
    printf("\n+==================================================+\n");

st:
    printf("\nEnter Weight Of Fabric Sample (gm): ");
    scanf("%f", &wt);

    printf("Enter Length Of Yarn (m): ");
    scanf("%f", &l);
    if (wt <= 0)
    {
        printf("\nWeight Must Be Greater Than Zero.\n");
        goto st;
    }
    if (l <= 0)
    {
        printf("\nLength Must Be Greater Than Zero.\n");
        goto st;
    }

    do
    {
        printf("\nSelect Yarn Count: ");
        printf("\n1. Tex");
        printf("\n2. Denier");
        printf("\n3. Metric Count (Nm)");
        printf("\n4. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            reportTex = (wt / l) * 1000;
            printf("\nFormula: Tex = [Weight (gm) / Length (m)] x 1000");
            printf("\nThe Yarn Count For %.2f gm Yarn Of %.2f m Length Is %.2f Tex.\n", wt, l, reportTex);
            break;

        case 2:
            reportDenier = (wt / l) * 9000;
            printf("\nFormula: Denier = [Weight (gm) / Length (m)] x 9000");
            printf("\nThe Yarn Count For %.2f gm Yarn Of %.2f m Length Is %.2f Denier.\n", wt, l, reportDenier);
            break;

        case 3:
            reportNm = l / wt;
            printf("\nFormula: Metric Count = [Length (m) / Weight (gm)]");
            printf("\nThe Yarn Count For %.2f gm Yarn Of %.2f m Length Is %.2f Nm.\n", wt, l, reportNm);
            break;

        case 4:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 4);
}

void fabricGSM()
{
    int choice;
    float wt, l, b;

    printf("\n+==================================================+");
    printf("\n|              FABRIC GSM CALCULATOR               |");
    printf("\n+==================================================+\n");

stw:
    printf("\nEnter Weight Of Fabric Sample (gm): ");
    scanf("%f", &wt);

    if (wt <= 0)
    {
        printf("\nWeight Must Be Greater Than Zero.\n");
        goto stw;
    }

    do
    {
        printf("\nSelect Dimension Of Fabric: ");
        printf("\n1. Metre (m)");
        printf("\n2. Centimetre (cm)");
        printf("\n3. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        stl1:
            printf("\nEnter Length Of Fabric (m): ");
            scanf("%f", &l);

            printf("Enter Width Of Fabric (m): ");
            scanf("%f", &b);

            if (l <= 0 || b <= 0)
            {
                printf("\nDimensions Must Be Greater Than Zero.\n");
                goto stl1;
            }
            reportGSM = wt / (l * b);
            printf("\nFormula: Area (m^2) = Length (m) x Width (m)");
            printf("\nFormula: GSM = Weight (g) / Area (m^2)");
            printf("\nThe GSM For The Fabric Is %.2f.\n", reportGSM);
            break;

        case 2:
        stl2:
            printf("\nEnter Length Of Fabric (cm): ");
            scanf("%f", &l);

            printf("Enter Width Of Fabric (cm): ");
            scanf("%f", &b);

            if (l <= 0 || b <= 0)
            {
                printf("\nDimensions Must Be Greater Than Zero.\n");
                goto stl2;
            }
            reportGSM = (wt / (l * b)) * 10000;
            printf("\nFormula: Area (m^2) = [Length (cm) x Width (cm)] / 10000");
            printf("\nFormula: GSM = Weight (g) / Area (m^2)");
            printf("\nThe GSM For The Fabric Is %.2f.\n", reportGSM);
            break;

        case 3:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 3);
}

void fabricProduction()
{
    int choice, tm, num;
    float ms, ef;

    printf("\n+==================================================+");
    printf("\n|           FABRIC PRODUCTION CALCULATOR           |");
    printf("\n+==================================================+\n");

st:
    printf("\nAssumption: Machine Speed Is Measured In Metres Per Hour.");
    printf("\nEnter Speed Of Machine: ");
    scanf("%f", &ms);

    printf("Enter Working Time Of Machine (in Hr): ");
    scanf("%d", &tm);

    printf("Enter Efficiency Of Machine (in %%): ");
    scanf("%f", &ef);

    printf("Enter Number Of Machines: ");
    scanf("%d", &num);

    if (ms <= 0 || tm <= 0 || ef < 0 || ef > 100 || num <= 0)
    {
        printf("\nEnter Positive Speed, Time And Machine Count; Efficiency Must Be 0-100%%.\n");
        goto st;
    }
    do
    {
        printf("\nSelect Fabric Production Mode: ");
        printf("\n1. Fabric Production Per Machine");
        printf("\n2. Fabric Production On All Machine");
        printf("\n3. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            reportProduction = ms * tm * ef * num / 100;
            printf("\nFormula: Production Per Machine = Speed x Working Time x (Efficiency / 100)");
            printf("\nThe Production Of Fabric Per Machine Is %.2f m.\n", ms * tm * ef / 100);
            break;

        case 2:
            reportProduction = ms * tm * ef * num / 100;
            printf("\nFormula: Total production = Production Per Machine x Number Of Machines");
            printf("\nThe Production Of Fabric On All Machines Is %.2f m.\n", reportProduction);
            break;

        case 3:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 3);
}

void costCalculator()
{
    int choice;
    float yn, ps, dye, fns, lbr, oth, mt, pr;

    printf("\n+==================================================+");
    printf("\n|         FABRIC PRODUCTION COST CALCULATOR        |");
    printf("\n+==================================================+\n");

st:
    printf("\nEnter Length Of Fabric Produced (In m): ");
    scanf("%f", &mt);

    printf("Enter Cost Of Yarn (In Rs.): ");
    scanf("%f", &yn);

    printf("Enter Cost Of Weaving/Knitting (In Rs.): ");
    scanf("%f", &ps);

    printf("Enter Cost Of Dyeing (In Rs.): ");
    scanf("%f", &dye);

    printf("Enter Cost Of Finishing (In Rs.): ");
    scanf("%f", &fns);

    printf("Enter Cost Of Labour (In Rs.): ");
    scanf("%f", &lbr);

    printf("Enter Other Costs (In Rs.): ");
    scanf("%f", &oth);

    printf("Enter Profit Margin (In %%): ");
    scanf("%f", &pr);

    if (mt <= 0 || yn < 0 || ps < 0 || dye < 0 || fns < 0 || lbr < 0 || oth < 0 || pr < 0)
    {
        printf("\nLength, Costs And Profit Margin Cannot Be Negative.\n");
        goto st;
    }

    do
    {
        printf("\nSelect Cost Calculator Mode: ");
        printf("\n1. Total Cost Of Fabric");
        printf("\n2. Cost Per Metre Of Fabric");
        printf("\n3. Profit Margin");
        printf("\n4. Selling Price");
        printf("\n5. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nFormula: Total cost = Yarn Cost + Weaving Cost + Dyeing Cost + Finishing Cost + Labour Charges + Other Costs");
            printf("\nThe Total Cost Of Fabric Is Rs. %.2f.\n", (yn + ps + dye + fns + lbr + oth));
            break;

        case 2:
            reportCostPerMetre = (yn + ps + dye + fns + lbr + oth) / mt;
            printf("\nFormula: Cost Per Metre = Total Cost / Total Fabric Length (m)");
            printf("\nThe Cost Of Fabric Per Metre Is Rs. %.2f.\n", reportCostPerMetre);
            break;

        case 3:
            reportCostPerMetre = (yn + ps + dye + fns + lbr + oth) / mt;
            reportProfit = reportCostPerMetre * pr / 100;
            printf("\nFormula: Profit Per Metre = Cost Per Metre x (Profit Percentage / 100)");
            printf("\nThe Profit On Fabric Per Metre Is Rs. %.2f.\n", reportProfit);
            break;

        case 4:
            reportCostPerMetre = (yn + ps + dye + fns + lbr + oth) / mt;
            reportProfit = reportCostPerMetre * pr / 100;
            reportSellingPrice = reportCostPerMetre + reportProfit;
            printf("\nFormula: Selling Price Per Metre = Cost Per Metre + Profit Per Metre");
            printf("\nThe Selling Price Of Fabric Per Metre Is Rs. %.2f.\n", reportSellingPrice);
            break;

        case 5:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 5);
}

void defectAnalysis()
{
    int choice, hl, stn, bed, bpk, slb, oth, ttl;
    float df;

    printf("\n+==================================================+");
    printf("\n|         FABRIC QUALITY & DEFECT ANALYSIS         |");
    printf("\n+==================================================+\n");

st:
    printf("\nEnter Total Number Of Holes In Fabric: ");
    scanf("%d", &hl);

    printf("Enter Total Number Of Stains In Fabric: ");
    scanf("%d", &stn);

    printf("Enter Total Number Of Broken Ends In Fabric: ");
    scanf("%d", &bed);

    printf("Enter Total Number Of Broken Picks In Fabric: ");
    scanf("%d", &bpk);

    printf("Enter Total Number Of Slubs In Fabric: ");
    scanf("%d", &slb);

    printf("Enter Total Number Of Other Defects In Fabric: ");
    scanf("%d", &oth);

stt:
    printf("Enter Total Unit Of Fabric Inspected: ");
    scanf("%d", &ttl);

    if (hl < 0 || stn < 0 || bed < 0 || bpk < 0 || slb < 0 || oth < 0)
    {
        printf("\nDefect Counts Cannot Be Negative.\n");
        goto st;
    }
    if (ttl <= 0)
    {
        printf("\nInspection Units Must Be Greater Than Zero.\n\n");
        goto stt;
    }
    df = ((hl + stn + bed + bpk + slb + oth) / (float)ttl) * 100;
    reportTotalDefects = hl + stn + bed + bpk + slb + oth;
    reportDefectPercent = df;
    if (reportTotalDefects == 0)
        strcpy(reportCommonDefect, "None");
    else if (hl >= stn && hl >= bed && hl >= bpk && hl >= slb && hl >= oth)
        strcpy(reportCommonDefect, "Holes");
    else if (stn >= bed && stn >= bpk && stn >= slb && stn >= oth)
        strcpy(reportCommonDefect, "Stains");
    else if (bed >= bpk && bed >= slb && bed >= oth)
        strcpy(reportCommonDefect, "Broken ends");
    else if (bpk >= slb && bpk >= oth)
        strcpy(reportCommonDefect, "Broken picks");
    else if (slb >= oth)
        strcpy(reportCommonDefect, "Slubs");
    else
        strcpy(reportCommonDefect, "Other defects");
    if (df < 2.0)
        strcpy(reportQuality, "Excellent");
    else if (df < 5.0)
        strcpy(reportQuality, "Good");
    else if (df < 10.0)
        strcpy(reportQuality, "Average");
    else
        strcpy(reportQuality, "Poor");

    do
    {
        printf("\nSelect Defect Analysis Mode: ");
        printf("\n1. Total Defects In Fabric");
        printf("\n2. Total Defect %% In Fabric");
        printf("\n3. Fabric Quality Analysis");
        printf("\n4. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nFormula: Total Defects = Holes + Stains + Broken Ends + Broken Picks + Slubs + Other Defects");
            printf("\nThe Total Number Of Defects In Fabric Is %d.\n", (hl + stn + bed + bpk + slb + oth));
            break;

        case 2:
            printf("\nFormula: Defect Percentage = (Total Defects / Total Inspection Units) x 100");
            printf("\nThe Total Defect %% Of Fabric Is %.2f%%.\n", df);
            break;

        case 3:
            printf("\nThe Total Defect %% Of Fabric Is %.2f%%.", df);
            if (df < 2.0)
                printf("\nThe Fabric Is Of Excellent Quality.\n");
            else if (df >= 2.0 && df < 5.0)
                printf("\nThe Fabric Is Of Good Quality.\n");
            else if (df >= 5.0 && df < 10.0)
                printf("\nThe Fabric Is Of Average Quality.\n");
            else if (df >= 10.0)
                printf("\nThe Fabric Is Of Poor Quality.\n");
            break;

        case 4:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 4);
}

void inventoryManagement()
{
    int choice, i, itemNo, categoryChoice, found;
    float amount;
    char search[50];

    printf("\n+==================================================+");
    printf("\n|           TEXTILE INVENTORY MANAGEMENT           |");
    printf("\n+==================================================+\n");

    do
    {
        printf("\n1. Add New Item");
        printf("\n2. Display All Items");
        printf("\n3. Search Item");
        printf("\n4. Update Stock Quantity");
        printf("\n5. Issue/Remove Stock");
        printf("\n6. Check Low-Stock Items");
        printf("\n7. Return To Main Menu");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (itemCount >= MAX_ITEMS)
            {
                printf("\nInventory Is Full.\n");
                break;
            }
            printf("\nEnter Item Name (No Spaces): ");
            scanf("%49s", search);
            found = 0;
            for (i = 0; i < itemCount; i++)
                if (strcmp(itemName[i], search) == 0)
                    found = 1;
            if (found)
            {
                printf("\nItem Already Exists.\n");
                break;
            }
            strcpy(itemName[itemCount], search);
        st11:
            printf("1. Yarn \n2. Fabric \n3. Dyes \n4. Chemicals \n5. Accessories\n");
            printf("Enter Category: ");
            scanf("%d", &categoryChoice);
            if (categoryChoice < 1 || categoryChoice > 5)
            {
                printf("\nInvalid Choice!!\n\n");
                goto st11;
            }

            if (categoryChoice == 1)
                strcpy(itemCategory[itemCount], "Yarn");
            else if (categoryChoice == 2)
                strcpy(itemCategory[itemCount], "Fabric");
            else if (categoryChoice == 3)
                strcpy(itemCategory[itemCount], "Dyes");
            else if (categoryChoice == 4)
                strcpy(itemCategory[itemCount], "Chemicals");
            else
                strcpy(itemCategory[itemCount], "Accessories");

        st12:
            printf("Enter Current Stock: ");
            scanf("%f", &amount);
            if (amount < 0)
            {
                printf("\nStock Cannot Be Negative.\n\n");
                goto st12;
            }
            itemStock[itemCount] = amount;
        st13:
            printf("Enter Reorder Level: ");
            scanf("%f", &amount);
            if (amount < 0)
            {
                printf("\nReorder Level Cannot Be Negative.\n\n");
                goto st13;
            }
            itemReorder[itemCount] = amount;
            itemCount++;
            printf("Item Added Successfully.\n");
            break;

        case 2:
            if (itemCount == 0)
            {
                printf("\nInventory Is Empty. Add Items To Continue..\n");
                break;
            }
            printf("\n+-----+----------------------+-----------------+--------------+--------------+\n");
            printf("| %-3s | %-20s | %-15s | %-12s | %-12s |\n", "No.", "Item", "Category", "Stock", "Reorder At");
            printf("+-----+----------------------+-----------------+--------------+--------------+\n");
            for (i = 0; i < itemCount; i++)
                printf("| %-3d | %-20.20s | %-15.15s | %12.2f | %12.2f |\n", i + 1, itemName[i], itemCategory[i], itemStock[i], itemReorder[i]);
            printf("+-----+----------------------+-----------------+--------------+--------------+\n");
            break;

        case 3:
            printf("\nEnter Item Name To Search (No Spaces): ");
            scanf("%49s", search);
            found = 0;
            for (i = 0; i < itemCount; i++)
                if (strcmp(itemName[i], search) == 0)
                {
                    printf("\nItem: %s | Category: %s | Stock: %.2f | Reorder Level: %.2f\n", itemName[i], itemCategory[i], itemStock[i], itemReorder[i]);
                    found = 1;
                    break;
                }
            if (!found)
                printf("\nItem Not Found.\n");
            break;

        case 4:
            if (itemCount == 0)
            {
                printf("\nInventory Is Empty. Add Items To Continue..\n");
                break;
            }

            printf("\nEnter Item Name To Search (No Spaces): ");
            scanf("%49s", search);

            found = 0;

            for (i = 0; i < itemCount; i++)
            {
                if (strcmp(itemName[i], search) == 0)
                {
                st41:
                    printf("Enter New Stock Quantity: ");
                    scanf("%f", &amount);

                    if (amount < 0)
                    {
                        printf("\nStock Cannot Be Negative.\n\n");
                        found = 1;
                        goto st41;
                    }

                    itemStock[i] = amount;

                    printf("\nStock Updated Successfully!\n");
                    printf("Item Name: %s\n", itemName[i]);
                    printf("New Stock: %.2f\n", itemStock[i]);

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\nItem Not Found.\n");
            }
            break;

        case 5:
            if (itemCount == 0)
            {
                printf("\nInventory Is Empty. Add Items To Continue..\n");
                break;
            }

            printf("\nEnter Item Name To Issue (No Spaces): ");
            scanf("%49s", search);

            found = 0;

            for (i = 0; i < itemCount; i++)
            {
                if (strcmp(itemName[i], search) == 0)
                {
                st51:
                    printf("Enter Quantity To Issue: ");
                    scanf("%f", &amount);

                    if (amount <= 0)
                    {
                        printf("\nEnter A Positive Quantity.\n\n");
                        found = 1;
                        goto st51;
                    }

                    if (amount > itemStock[i])
                    {
                        printf("\nInsufficient Stock.\n");
                        found = 1;
                        break;
                    }

                    itemStock[i] -= amount;

                    printf("\nStock Issued Successfully!\n");
                    printf("Item Name: %s\n", itemName[i]);
                    printf("Issued Quantity: %.2f\n", amount);
                    printf("Remaining Stock: %.2f\n", itemStock[i]);

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\nItem Not Found.\n");
            }

            break;

        case 6:
            found = 0;
            for (i = 0; i < itemCount; i++)
            {
                if (itemStock[i] <= itemReorder[i])
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nNo Low-Stock Items.\n");
            }
            else
            {
                printf("\n+---------------------------------------------------------------+\n");
                printf("|                        LOW-STOCK ITEMS                        |\n");
                printf("+----------------------+--------------+--------------+----------+\n");
                printf("| %-20s | %-12s | %-12s | %-8s |\n", "Item", "Current", "Reorder At", "Status");
                printf("+----------------------+--------------+--------------+----------+\n");
                for (i = 0; i < itemCount; i++)
                    if (itemStock[i] <= itemReorder[i])
                    {
                        printf("| %-20.20s | %12.2f | %12.2f | %-8s |\n", itemName[i], itemStock[i], itemReorder[i], "REORDER");
                        found = 1;
                    }
                printf("+----------------------+--------------+--------------+----------+\n");
            }
            break;

        case 7:
            printf("\nReturning To Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }
    } while (choice != 7);
}

void finalReport()
{

    int i, lowCount = 0;
    char result[42];

    printf("\n");
    printf("+============================================================================+\n");
    printf("|                    TEXTILE PRODUCTION & QUALITY REPORT                     |\n");
    printf("|                          CONSOLIDATED SUMMARY                              |\n");
    printf("+============================================================================+\n");
    printf("|                        PRODUCTION, COST AND QUALITY                        |\n");
    printf("+================================+===========================================+\n");
    printf("| %-30s | %-41s |\n", "REPORT PARAMETER", "RESULT");
    printf("+--------------------------------+-------------------------------------------+\n");

    if (reportTex >= 0)
        snprintf(result, sizeof(result), "%.2f Tex", reportTex);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Yarn Count (Tex)", result);


    if (reportDenier >= 0)
        snprintf(result, sizeof(result), "%.2f Denier", reportDenier);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Yarn Count (Denier)", result);

    
    if (reportNm >= 0)
        snprintf(result, sizeof(result), "%.2f Nm", reportNm);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Yarn Count (Nm)", result);

    
    if (reportGSM >= 0)
        snprintf(result, sizeof(result), "%.2f GSM", reportGSM);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Fabric GSM", result);

    
    if (reportProduction >= 0)
        snprintf(result, sizeof(result), "%.2f units", reportProduction);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Total Production", result);

    
    if (reportCostPerMetre >= 0)
        snprintf(result, sizeof(result), "Rs. %.2f", reportCostPerMetre);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Cost Per Metre", result);

    
    if (reportProfit >= 0)
        snprintf(result, sizeof(result), "Rs. %.2f", reportProfit);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Profit Per Metre", result);

    
    if (reportSellingPrice >= 0)
        snprintf(result, sizeof(result), "Rs. %.2f", reportSellingPrice);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Selling Price Per Metre", result);

    if (reportTotalDefects >= 0)
        snprintf(result, sizeof(result), "%d", reportTotalDefects);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Total Defects", result);

    if (reportDefectPercent >= 0)
        snprintf(result, sizeof(result), "%.2f%%", reportDefectPercent);
    else
        snprintf(result, sizeof(result), "Not Calculated");
    printf("| %-30s | %-41s |\n", "Defect Percentage", result);

    printf("| %-30s | %-41.41s |\n", "Quality Grade", reportQuality);
    printf("| %-30s | %-41.41s |\n", "Most Common Defect", reportCommonDefect);

    printf("+============================================================================+\n");

    printf("\n+============================================================================+\n");
    printf("|                            INVENTORY SUMMARY                               |\n");
    printf("+============================================================================+\n");

    if (itemCount == 0)
    {
        printf("| %-74s |\n", "No Inventory Items Added Yet.");
    }
    else
    {
        printf("| %-3s | %-16s | %-12s | %-9s | %-9s | %-10s |\n",
               "No.", "Item", "Category", "Stock", "Reorder", "Status");

        printf("+-----+------------------+--------------+-----------+-----------+------------+\n");

        for (i = 0; i < itemCount; i++)
        {
            const char *status;

            if (itemStock[i] <= itemReorder[i])
            {
                lowCount++;
                status = "LOW STOCK";
            }
            else
            {
                status = "Available";
            }

            printf("| %-3d | %-16.16s | %-12.12s | %9.2f | %9.2f | %-10s |\n",
                   i + 1,
                   itemName[i],
                   itemCategory[i],
                   itemStock[i],
                   itemReorder[i],
                   status);
        }

        printf("+-----+------------------+--------------+-----------+-----------+------------+\n");

        printf("| Total Inventory Items : %-50d |\n", itemCount);
        printf("| Low-Stock Items       : %-50d |\n", lowCount);
    }

    printf("+============================================================================+\n");
    printf("|                  END OF REPORT - TEXTILE MANAGEMENT SYSTEM                 |\n");
    printf("+============================================================================+\n\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n+======================================================+");
        printf("\n|       TEXTILE PRODUCTION & QUALITY MANAGEMENT        |");
        printf("\n|                      MAIN MENU                       |");
        printf("\n+======================================================+\n");
        printf("\n1. Yarn Count Calculator");
        printf("\n2. Fabric GSM Calculator");
        printf("\n3. Fabric Production Calculator");
        printf("\n4. Fabric Production Cost Calculator");
        printf("\n5. Fabric Quality & Defect Analysis");
        printf("\n6. Textile Inventory Management");
        printf("\n7. Generate Final Report");
        printf("\n8. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            yarnCount();
            break;

        case 2:
            fabricGSM();
            break;

        case 3:
            fabricProduction();
            break;

        case 4:
            costCalculator();
            break;

        case 5:
            defectAnalysis();
            break;

        case 6:
            inventoryManagement();
            break;

        case 7:
            finalReport();
            break;

        case 8:
            printf("\nThank You!!\n");
            break;

        default:
            printf("\nInvalid Choice!! Enter Again!!\n");
        }

    } while (choice != 8);

    return 0;
}
